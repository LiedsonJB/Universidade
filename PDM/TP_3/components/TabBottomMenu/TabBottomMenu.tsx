import { Text, TextStyle, TouchableOpacity, View } from 'react-native';
import styles from './TabBottomMenu.style';

type TabProps = {
    selectedTabName: string;
    onPress: (tab: string) => void;
    todoList: Todo[];
};

type Todo = {
    id: number;
    title: string;
    isCompleted: boolean;
};

const TabBottomMenu = ({ selectedTabName , todoList, onPress}: TabProps) => {

    const getTextStyle = (tabName: string): TextStyle => {

        return {
            fontWeight: 'bold',
            fontSize: 20,
            color: selectedTabName === tabName ? '#7286A0' : '#CDE7B0',
        };
    };

    const countByStatus = todoList.reduce(
        (acumulador, todo) => {
            todo.isCompleted ? acumulador.fet++ : acumulador.quase++;
            return acumulador;
        },
        {
            tud: todoList.length,
            quase: 0,
            fet: 0,
        },
    );

    return (

        <View style={styles.root}>

            <TouchableOpacity onPress={() => onPress('Tud')}>
                <Text style={getTextStyle('Tud')}>Tud ({countByStatus.tud})</Text>
            </TouchableOpacity>

            <TouchableOpacity onPress={() => onPress('Quase')}>
                <Text style={getTextStyle('Quase')}>Quase  ({countByStatus.quase})</Text>
            </TouchableOpacity>

            <TouchableOpacity onPress={() => onPress('Fet')}>
                <Text style={getTextStyle('Fet')}>Fet  ({countByStatus.fet})</Text>
            </TouchableOpacity>

        </View>
    );
};


export default TabBottomMenu;