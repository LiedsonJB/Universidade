import jwt from "jsonwebtoken";
import User from "../models/User.js";
import "dotenv/config";

const routeProtection = async (req, res, next) => {

    try {

        const authHeader = req.header("Authorization");

        if (!authHeader) {
            return res.status(401).json({ 
                message: "Sem token de autenticação, acesso negado." 
            });
        }

        const token = authHeader.replace("Bearer ", "");

        if (!token)
            return res.status(401).json({ 
                message: "Sem token de autenticação, acesso negado."
             });

        const decoded = jwt.verify(token, process.env.JWT_SECRET);

        const user = await User.findById(decoded.userId).select("-password");

        if (!user)
            return res.status(401).json({ message: "Token inválido." });

        req.user = user;
        next();

    } catch (error) {
        console.log("Erro ao criar book", error.message);
        res.status(401).json({ message: "Token inválido" });
    }
};