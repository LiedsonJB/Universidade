// Arquivo principal da aplicação
// Importa o NavigationContainer que envolve toda a navegação
import StackNavigator from "./navigation/StackNavigator";
import { NavigationContainer } from '@react-navigation/native'

// Componente raiz que configura a navegação
function App() {

  return (
    // NavigationContainer: permite usar navegação na app
    <NavigationContainer>
      {/* StackNavigator: define todas as telas disponíveis */}
      <StackNavigator />
    </NavigationContainer>
  );

}

export default App;
