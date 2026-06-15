import express from "express";
import User from "../models/User.js";
import jwt from "jsonwebtoken";

const router = express.Router();

const generateToken = (userId) => {

    return jwt.sign({ userId }, process.env.JWT_SECRET, { expiresIn: "15d" });
    
}

router.post("/signUp", async (req, res) => {

    try {

        const { email, username, password } = req.body;

        if (!email || !username || !password) {
            return res.status(400).json({ message: "Todos os campos são obrigatórios" });
        }

        if (password.length < 8) {
            return res.status(400).json({ message: "A palavra-passe deve ter pelo menos 8 caracteres." });
        }

        if (username.length < 3) {
            return res.status(400).json({ message: "O username deve ter pelo menos 3 caracteres." });
        }

        //Verificar se o utilizador já existe
        const existingEmail = await User.findOne({ email });

        if (existingEmail)
            return res.status(400).json({ message: "O email já existe!" });

        const existingUsername = await User.findOne({ username });

        if (existingUsername)
            return res.status(400).json({ message: "O username já existe!" });

        // avatar aleatório (para a imagem de perfil)
        const profileImage = `https://api.dicebear.com/7.x/avataaars/svg?seed=${username}`;

        const user = new User({
            email,
            username,
            password,
            profileImage,
        });

        await user.save();

        const token = generateToken(user._id);

        // Enviar o token e os dados do utilizador para o cliente (React Native)
        res.status(201).json({
            token,
            user: {
                id: user._id,
                username: user.username,
                email: user.email,
                profileImage: user.profileImage
            },
        })

    } catch (error) {

        console.log("Erro na rota signUp", error);
        res.status(500).json("Erro na rota signUp", error.message);

    }

});

router.post("/signIn", async (req, res) => {

    try {

        const { email, password } = req.body;

        if (!email || !password)
            return res.status(400).json({ message: "Todos os campos são obrigatórios!" });

        // Verifica se o utilizador existe
        const user = await User.findOne({ email });

        if (!user)
            return res.status(400).json({ message: "Utilizador não existe!" });

        // Verifica se o password está correto
        const isPasswordCorrect = await user.comparePassword(password);

        if (!isPasswordCorrect)
            return res.status(400).json({ message: "Credenciais inválidos!" });

        // Gerar JWT token
        const token = generateToken(user._id);

        res.status(200).json({
            token,
            user: {
                id: user._id,
                username: user.username,
                email: user.email,
                profileImage: user.profileImage
            },
        });

    } catch (error) {

        console.log("Erro na rota signIn", error);
        res.status(500).json("Erro na rota signIn", error.message);

    }
});

export default router;