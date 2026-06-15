import styles from './CardTodo.style'
import { Alert, Image, Text, TouchableOpacity } from 'react-native';
import { useRef } from 'react';

type Todo = {
    id: number;
    title: string;
    isCompleted: boolean;
};

type TodoProps = {
    todos: Todo;
    onPress: (todo: Todo) => void
};


const CardTodo = ({ todos, onPress }: TodoProps) => {
    const time = useRef<ReturnType<typeof setTimeout> | null>(null);

    const pressIn = () =>{
        time.current = setTimeout(() => {
            Alert.alert(
                'Alerta',
                `Você pressionou o item "${todos.title}" por 5 segundos!`,
                [{ text: 'OK' }]
            );
        }, 50);}

    const pressOut = () =>{
          if (time.current) {
            clearTimeout(time.current);
            time.current = null;
        }
    }

    return (
        <TouchableOpacity onPress={() => onPress(todos)} style={styles.card}>
            <Text style={[
                styles.title,
                todos.isCompleted && { textDecorationLine: 'line-through' },
            ]}

            onPressIn={pressIn}
            onPressOut={pressOut}
            >
                {todos.title}
            </Text>

            {todos.isCompleted && (
                <Image style={styles.img} source={require('../../assets/check.png')} />
            )}

        </TouchableOpacity>
    );
};

export default  CardTodo;