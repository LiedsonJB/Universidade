// Componente de fundo com imagem de fundo e sobreposição
// Recebe `url` (fonte da imagem) e `children` para renderizar o conteúdo por cima
import { ImageBackground, View, type ImageSourcePropType } from "react-native";
import style from "./background.style";

type BackgroundProps = {
  // Fonte da imagem (require/imports do projeto)
  url: ImageSourcePropType;
  // Qualquer conteúdo filho será renderizado sobre o fundo
  children?: React.ReactNode;
};

function Background({ url, children }: BackgroundProps) {
  // ImageBackground preenche a área e o View interno aplica padding/overlay
  return (
    <ImageBackground source={url} resizeMode="cover" style={style.container}>
      <View style={style.overlay}>{children}</View>
    </ImageBackground>
  );
}

export default Background