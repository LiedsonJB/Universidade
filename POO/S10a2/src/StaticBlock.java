public class StaticBlock {
    static double f1;
    static double f2;

    static {
        f1 = Math.sqrt(2.0);
        f2 = Math.sqrt(4.0);
    }

    public StaticBlock(String sms){
        System.out.println(sms);
        System.out.println(f1);
        System.out.println(f2);
    }
}
