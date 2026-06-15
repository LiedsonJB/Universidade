import { View, Text, Image, ScrollView, KeyboardAvoidingView, Platform, TouchableOpacity } from 'react-native';
import styles from "./style";
import { Input } from "./components/Input/Input";
import { Button } from './components/Button/Button';

export default function Login({ navigation }: any) {

    return (
        <KeyboardAvoidingView style={{ flex: 1 }} behavior={Platform.select({ ios: "padding", android: "height" })}>
            <ScrollView contentContainerStyle={{ flexGrow: 1 }} keyboardShouldPersistTaps="handled" showsHorizontalScrollIndicator={false}>

                <View style={styles.container}>
                    <Image source={require("./asset/log.png")} style={styles.ilustracao} />

                    <Text style={styles.title}>Entrar </Text>
                    <Text style={styles.subtitle}>Acessa sua conta com email e senha</Text>

                    <View style={styles.from}>
                        <Input placeholder="Seu Email" keyboardType="email-address" />
                        <Input placeholder="Sua Senha" secureTextEntry />

                        <Button label='Entrar' />

                        <View style={{ flexDirection: "row", alignItems: "center", justifyContent: "center"}}>
                            <Text style={styles.footerText}>Nao tem uma conta? {" "} </Text>

                            <TouchableOpacity onPress={() => navigation.navigate("SignUp")}>
                                <Text style={styles.footerLink}>Cadastra-se aqui</Text>
                            </TouchableOpacity>

                        </View>
                    </View>
                </View>

            </ScrollView>
        </KeyboardAvoidingView>
    );
}