public abstract class Paycalculator {
    private double payRate;

    public Paycalculator(double payrate){
        this.payRate = payrate;
    }

    public double getPayRate(){return this.payRate;}

    public abstract double computePay(int hours);
}
