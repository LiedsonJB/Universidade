import express from "express";

const router = express.Router();

router.post("/", routeProtection, async (req, res) => {

    try {
        const { title, caption, rating, image } = req.body;

        if (!image || !title || !caption || !rating)
            return res.status(400).json({
                message: "Por favor, preencha todos os campos."
            });

        // Upload da imagem no cloudinary
        const uploadResponse = await cloudinary.uploader.upload(image);
        const imageUrl = uploadResponse.secure_url;

        //Guardar na base de dados
        const newBook = new Book({
            title,
            caption,
            rating,
            image: imageUrl,
            user: req.user._id,
        });

        await newBook.save();
        res.status(201).json(newBook);

    } catch (error) {
        console.log("Erro ao criar book", error);
        res.status(500).json({ message: error.message });
    }
});

router.get("/", routeProtection, async (req, res) => {
    try {

        const page = req.query.page || 1;
        const limit = req.query.limit || 5;
        const skipPage = (page - 1) * limit;

        const books = await Book.find()
            .sort({ createdAt: -1 })
            .skip(skipPage)
            .limit(limit)
            .populate("user", "username profileImage");

        const totalBooks = await Book.countDocuments();

        //se status não for especificado, por padrão, será 200
        res.send({
            books,
            currentPage: page,
            totalBooks,
            totalPages: Math.ceil(totalBooks / limit),

        });

    } catch (error) {
        console.log("Erro ao ler books", error);
        res.status(500).json({ message: error.message });
    }
});

router.get("/user", routeProtection, async (req, res) => {

    try {
        const books = await Book.find({ user: req.user._id }).sort({ createdAt: -1 });

        res.send(books);

    } catch (error) {
        console.log("Erro ao ler books do user", error);
        res.status(500).json({ message: error.message });
    }
});

router.delete("/:id", routeProtection, async (req, res) => {

    try {

        const book = await Book.findById(req.params.id);

        if (!book)
            return res.status(400).json({ message: "Book não existe." });
       
        //Verificar se user foi quem criou este book
        if (book.user.toString() !== req.user._id.toString())
            return res.status(401).json({ message: "Sem autorização" });
       
        //COLOCAR URL DE CLOUDINARY AQUI
        // Apagar a imagem do book do cloudinary
        if (book.image && book.image.includes("cloudinary")) {

            try {
                const publicId = book.image.split("/").pop().split(".")[0];
                await cloudinary.uploader.destroy(publicId);
            
            } catch (error) {
                console.log("Erro ao apagar imagem do cloudinary", error);
                res.status(500).json({ message: error.message });
            }
        }

        await book.deleteOne();
        res.json({ message: "book apagado com sucesso." })
        
    } catch (error) {
        console.log("Erro ao apagar book", error);
        res.status(500).json({ message: error.message });
    }
});

export default router;