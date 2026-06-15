/**
 * Entry point da aplicação React Native.
 * Regista o componente raiz (`App`) para que o sistema inicie a aplicação.
 */

import { AppRegistry } from 'react-native';
import App from './App';
import { name as appName } from './app.json';

// Regista o componente principal com o nome definido em app.json
AppRegistry.registerComponent(appName, () => App);
