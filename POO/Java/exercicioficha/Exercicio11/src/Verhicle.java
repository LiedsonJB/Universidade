public class Verhicle {
    private String regNo;
    private String make;
    private int yearOfManufacture;
    private double value;

    // Construtor
    public Verhicle(String regNo, String make, int yearOfManufacture, double value) {
        this.regNo = regNo;
        this.make = make;
        this.yearOfManufacture = yearOfManufacture;
        this.value = value;
    }

    // Métodos
    public String getRegNo() {
        return regNo;
    }

    public String getMake() {
        return make;
    }

    public int getYearOfManufacture() {
        return yearOfManufacture;
    }

    public double getValue() {
        return value;
    }

    public void setValue(double value) {
        this.value = value;
    }

    public int calculateAge(int currentYear) {
        return currentYear - yearOfManufacture;
    }
}
