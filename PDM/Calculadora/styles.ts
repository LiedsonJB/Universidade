import { StyleSheet } from "react-native";

const styles = StyleSheet.create({
  container: {
    flexDirection: "column",
    gap: 10,
    justifyContent: "center",
    alignItems: "center",
    borderColor: "#1cadf0",
    borderWidth: 3,
    borderRadius: 5,
    padding: 10,
    backgroundColor: "#000079",
    width: "90%",
  },
  rows: {
    flexDirection: "row",
    gap: 10,
  },
  
 root: {
    flex: 1,
    backgroundColor: "#000079",
    alignContent: "center",
    justifyContent: "center",
    alignItems: "center"
  }
});

export default styles;