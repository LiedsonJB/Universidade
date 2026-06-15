import { View, Text, Image, ScrollView, KeyboardAvoidingView, Platform, TouchableOpacity } from 'react-native';
import styles from "./style";
import { Input } from "./components/Input/Input";
import { Button } from './components/Button/Button';

export default function SignUp({ navigation }: any) {

    return (
        <KeyboardAvoidingView style={{ flex: 1 }} behavior={Platform.select({ ios: "padding", android: "height" })}>
            <ScrollView contentContainerStyle={{ flexGrow: 1 }} keyboardShouldPersistTaps="handled" showsHorizontalScrollIndicator={false}>

                <View style={styles.container}>

                    <Image source={require("./asset/log.png")} style={styles.ilustracao} />

                    <Text style={styles.title}>Cadastrar </Text>

                    <Text style={styles.subtitle}>Cria sua conta para acessar</Text>

                    <View style={styles.from}>
                        <Input placeholder="Seu Nome" />
                        <Input placeholder="Seu Email" keyboardType="email-address" />

                        <Input placeholder="Sua Senha" secureTextEntry />
                        <Input placeholder="Confirmar sua Senha" secureTextEntry />

                        <Button label='Cadastrar' />

                        <View style={{ flexDirection: "row", alignItems: "center", justifyContent: "center"}}>
                            <Text style={styles.footerText}>Ja tem uma conta? {" "} </Text>

                            <TouchableOpacity onPress={() => navigation.navigate("Login")}>
                                <Text style={styles.footerLink}>Entrar aqui</Text>
                            </TouchableOpacity>
                        </View>
                    </View>

                </View>

            </ScrollView>
        </KeyboardAvoidingView>
    )
}