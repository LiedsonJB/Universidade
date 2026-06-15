import mongoose from 'mongoose';
import bcrypt from 'bcryptjs';

// estrutura dos meus dados
const userSchema = new mongoose.Schema({

    username: {
        type: String,
        required: true,
        unique: true
    },

    email: {
        type: String,
        required: true,
        unique: true
    },

    password: {
        type: String,
        required: true,
        minlength: 8
    },

    profileImage: {
        type: String,
        default: ""
    },

}, { timestamps: true });

//gerar o hash da palavra-passe antes de guardar na BD
userSchema.pre("save", async function () {

    //se a password nao for modificada, nao e preciso gerar hash
    if (!this.isModified("password"))
        return;

    const salt = await bcrypt.genSalt(10);
    this.password = await bcrypt.hash(this.password, salt);
});


userSchema.methods.comparePassword = async function (userPassword) {
    
    return await bcrypt.compare(userPassword, this.password);

}

const User = mongoose.model("User", userSchema);
export default User;