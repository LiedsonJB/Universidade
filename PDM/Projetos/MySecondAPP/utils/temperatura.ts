const UNITS = {
    celsius: "ºC",
    fahrenheit: "ºF",
};

type convertProps = {
    unitTo: string;
    temperature: number;
}
type unitProps = {
    unit: string;
}
const convertTemperature = ({ temperature, unitTo }: convertProps) => {
    if (unitTo === UNITS.celsius) {

        return (temperature - 32) / 1.8;
    }
    else if (unitTo === UNITS.fahrenheit) {
        return temperature * 1.8 + 32;
    }
    else {
        throw new Error("Invalid unit");
    }
}
const getOppositeUnit = ({ unit }: unitProps) => {
    return unit === UNITS.celsius ? UNITS.fahrenheit : UNITS.celsius
}
export { UNITS, convertTemperature, getOppositeUnit }