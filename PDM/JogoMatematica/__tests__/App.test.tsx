/**
 * Teste simples: garante que o componente `App` renderiza sem crash.
 * Usa o renderer de teste para montar o componente.
 */

import React from 'react';
import ReactTestRenderer from 'react-test-renderer';
import App from '../App';

test('renders correctly', async () => {
  // Act monta o componente dentro do ambiente de teste
  await ReactTestRenderer.act(() => {
    ReactTestRenderer.create(<App />);
  });
});
