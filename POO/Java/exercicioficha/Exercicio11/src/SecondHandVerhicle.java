public class SecondHandVerhicle extends Verhicle {
    private int numberOfOwners;

    // Construtor
    public SecondHandVerhicle(String regNo, String make, int yearOfManufacture, double value, int numberOfOwners) {
        super(regNo, make, yearOfManufacture, value);
        this.numberOfOwners = numberOfOwners;
    }

    // Métodos
    public int getNumberOfOwners() {
        return numberOfOwners;
    }

    public boolean hasMultipleOwners() {
        return numberOfOwners > 1;
    }
}
