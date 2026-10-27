public class ArithmeticOperators {
    public static void main(String[] args) {
        int a = 17, b = 5;

        System.out.println("a + b = " + (a + b));
        System.out.println("a - b = " + (a - b));
        System.out.println("a * b = " + (a * b));
        System.out.println("a / b = " + (a / b)); // integer division, gives 3 not 3.4
        System.out.println("a % b = " + (a % b));
        System.out.println("a / (double)b = " + (a / (double) b));
    }
}
