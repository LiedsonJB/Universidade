import { View, ImageBackground, ScrollView, Alert } from "react-native";
import { SafeAreaProvider, SafeAreaView } from "react-native-safe-area-context";
import { useEffect, useState } from "react";
import styles from "./styles";
import Input from "./components/Input";
import MyText from "./components/MyText/MyText";
import { UNITS, getOppositeUnit, convertTemperature } from "./utils/temperatura";
import ButtonConvert from "./components/ButtinConvert/ButtonConvert";

function App() {

  const [inputValue, setInputValue] = useState(0);
  const [currentUnit, setCurrentUnit] = useState("ºC")
  const oppositeUnit = getOppositeUnit({ unit: currentUnit })
  const [fundo, setFundo] = useState(require("./FILE/hot.png"));

  useEffect(() => {

    if ((inputValue > 25 && currentUnit === UNITS.celsius) || (inputValue > 77 && UNITS.fahrenheit === currentUnit)) {
      setFundo(require("./FILE/hot.png"));

    } else {

      setFundo(require("./FILE/cold.png"))

    }
  }, [inputValue, currentUnit]);

  return (

    <ImageBackground style={styles.BackgroundImg} source={fundo}>

      <SafeAreaProvider>
        <ScrollView>
          <SafeAreaView style={styles.screen}>

            <View style={styles.container}>

              <MyText temperature={convertTemperature({ temperature: inputValue, unitTo: oppositeUnit })}
                units={getOppositeUnit({ unit: currentUnit })}
              />

              <Input
                units={currentUnit}

                onChange={(valor) => {
                  if (isNaN(Number(valor))) {
                    Alert.alert("Erro", "Introduza um valor válido")

                    // nao consegui eliminar o valor na tela

                    return;
                  }else{
                    setInputValue(valor)
                  }
                  
                }}

                defaultValue={0}
                keyboardType={"numeric"}

                valor={inputValue.toString()}
                //editavel = {false}

              />

              <ButtonConvert onPress={() => {
                setCurrentUnit(oppositeUnit);
              }} units={currentUnit} />

            </View>

          </SafeAreaView>
        </ScrollView>
      </SafeAreaProvider>
    </ImageBackground>

  )

}


export default App;