public class LambdaDemo {
    public static void main(String[] args) {
        MyValue myVal = ()-> 98.6;
        Myparamvalue myPval = (n)-> 1.0/n;
        System.out.println("O valor: " + myVal.getValue());

        System.out.printf("Inverso de 4: " + myPval.getValue(4.0));
        System.out.println("Inverso de 8: " + myPval.getValue(8.0));

        RaizQuadrada raizQ = (n)-> Math.sqrt(n);
        Myparamvalue raiz1 = (n)-> Math.sqrt(n);

        System.out.printf("Raiz quadrada de 25: " + raizQ.raiz(25.0));
        System.out.println("Raiz de 81: " + myPval.getValue(25.0));

    }
}
