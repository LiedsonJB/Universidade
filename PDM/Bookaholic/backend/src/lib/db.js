import mongoose from "mongoose";

export const connectDB = async () => {

    try {
        const con = await mongoose.connect(process.env.MONGO_URI);
        console.log(`Database connected ${con.connection.host}`);
    }
    catch (error) {
        console.log("Error connecting to database", error);
        process.exit(1); // termina com erro
    }
    
}