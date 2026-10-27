public class FinallyDemo {
    public static void main(String[] args) {
        try {
            int n = 25 / 0;
            System.out.println(n);
        } catch (ArithmeticException e) {
            System.out.println("Exception: " + e.getMessage());
        } finally {
            // finally executes whether exception occurs or not
            System.out.println("finally block executed");
        }

        System.out.println("after try catch finally");
    }
}
