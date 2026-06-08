public class Main {
    public static void main(String[] args) {
        Verhicle vehicle = new Verhicle("ABC123", "Toyota", 2015, 15000);
        System.out.println("Registro: " + vehicle.getRegNo());
        System.out.println("Marca: " + vehicle.getMake());
        System.out.println("Ano de fabricação: " + vehicle.getYearOfManufacture());
        System.out.println("Valor: " + vehicle.getValue());
        System.out.println("Idade: " + vehicle.calculateAge(2025));

        SecondHandVerhicle secondHandVehicle = new SecondHandVerhicle("XYZ789", "Honda", 2010, 10000, 3);
        System.out.println("Registro: " + secondHandVehicle.getRegNo());
        System.out.println("Número de proprietários: " + secondHandVehicle.getNumberOfOwners());
        System.out.println("Possui múltiplos proprietários: " + secondHandVehicle.hasMultipleOwners());
    }
}
