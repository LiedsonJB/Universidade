import { Modal, ScrollView, View, Text, TextInput, ImageBackground } from 'react-native'
import { SafeAreaProvider, SafeAreaView } from 'react-native-safe-area-context'
import Swipeable from 'react-native-gesture-handler/Swipeable'
import Style from './styles'
import { GestureHandlerRootView } from 'react-native-gesture-handler';
import Header from './components/Header/Header'
import CardTodo from './components/CardFaze/CardTodo'
import { useState } from 'react'
import TabBottomMenu from './components/TabBottomMenu/TabBottomMenu'
import ButtonAdd from './components/ButtonAdd/ButtonAdd'
import Buttons from './components/Buttons/Buttons'
import ButtunLixeira from './components/Lixeira/Lixeira';

type Todo = {
  id: number;
  title: string;
  isCompleted: boolean;
};

export default function App() {

  const [modalVisible, setModalVisible] = useState(false);
  const [novoTitulo, setNovoTitulo] = useState('');

  const [selectedTabName, setSelectedtabName] = useState('Tud')
  const [todoList, setTodoList] = useState([

    { id: 1, title: 'Fazer o tutorial de PDM', isCompleted: false },
    { id: 2, title: 'Fazer os mockups do projeto de PDM', isCompleted: false },

    {
      id: 3,
      title: 'Assistir o novo episódio de One Piece',
      isCompleted: true,

    },

    { id: 4, title: 'Fazer o tutorial de PDM', isCompleted: false },
    { id: 5, title: 'Fazer os mockups do projeto de PDM', isCompleted: false },

    {
      id: 6,
      title: 'Assistir o novo episódio de One Piece',
      isCompleted: true,

    },

    { id: 7, title: 'Fazer o tutorial de PDM', isCompleted: false },
    { id: 8, title: 'Fazer os mockups do projeto de PDM', isCompleted: false },

    {
      id: 9,
      title: 'Assistir o novo episódio de One Piece',
      isCompleted: true,
    },

  ]);

  const updateTodo = (todo: Todo) => {
    const updatedTodo = {
      ...todo,
      isCompleted: !todo.isCompleted,
    };

    const updatedTodoList = [...todoList];
    const indexToUpdate = updatedTodoList.findIndex(
      t => t.id === updatedTodo.id,
    );

    updatedTodoList[indexToUpdate] = updatedTodo;
    setTodoList(updatedTodoList);
  }

  const renderRightActions = (id: number) => {
    return (
      <ButtunLixeira onpress={() => { setTodoList(todoList.filter(todo => todo.id !== id)) }} />
    );
  };

  const renderTodoList = (filteredTodos: Todo[]) => {

    if (todoList !== null) {
      return filteredTodos.map((todo) => (

        <View key={todo.id} style={Style.cardItem}>

          <Swipeable renderRightActions={() => renderRightActions(todo.id)}>

            <CardTodo onPress={updateTodo} todos={todo} />


          </Swipeable>
        </View>

      ));
    } else {
      return (
        <Text>Sem nada</Text>
      );
    }

  };

  const fecharModal = () => {
    setModalVisible(false);
    setNovoTitulo('');

  };

  const submeterDados = () => {
    if (novoTitulo.trim()) {
      const novoTodo: Todo = {
        id: Date.now(),
        title: novoTitulo,
        isCompleted: false,

      };

      setTodoList([novoTodo, ...todoList]);
      fecharModal();
    }
  };

  return (

    <GestureHandlerRootView style={Style.teste} >
      <SafeAreaProvider>
        <SafeAreaView style={Style.app}>

          <View style={Style.header}><Header /></View>

          <View style={Style.body}>
            <ScrollView>
              {renderTodoList(todoList)}
            </ScrollView>
            <ButtonAdd onPress={() => setModalVisible(true)} />

          </View>

          <View style={Style.footer}>

            <TabBottomMenu
              todoList={todoList}
              onPress={setSelectedtabName}
              selectedTabName={selectedTabName}
            />

          </View>

        </SafeAreaView>

        <Modal
          visible={modalVisible}
          animationType="slide"
          transparent={true}
          style={{alignItems: "center", justifyContent: "center",
            position: 'relative',
            width: "80%",
            height: "20%",

          }}
        >

          <ImageBackground
            source={require("./assets//images.jpeg")}
            blurRadius={10}
            resizeMode='cover'
            style={{alignItems: "center", justifyContent: "center",
                position: 'absolute',
                top: "20%",
                width: "100%",
                height: "50%",

            }}
          >

          <View style={Style.modalContainer}>
            <View style={Style.modalContent}>

              <Text>Titulo:</Text>
              <TextInput
                value={novoTitulo}
                onChangeText={setNovoTitulo}
                placeholder="Digite o título" style={Style.pesquisar}
              />

              <View style={Style.buttonsModal}>

                <Buttons Valor={'Cancelar'} onPress={fecharModal} />
                <Buttons Valor={'Submeter'} onPress={submeterDados} />

              </View>

            </View>
          </View>
        </ImageBackground>

      </Modal>

    </SafeAreaProvider>

    </GestureHandlerRootView >

  )

}