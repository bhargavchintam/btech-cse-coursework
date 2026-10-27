public class ThrowsDemo {
    static void divide(int a, int b) throws Exception {
        if (b == 0)
            throw new Exception("divisor is zero");
        System.out.println("Result = " + a / b);
    }

    public static void main(String[] args) {
        try {
            divide(10, 2);
            divide(10, 0);  // have to catch or declare
        } catch (Exception e) {
            System.out.println("caught: " + e.getMessage());
        }
    }
}
