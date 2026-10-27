public class TryCatchIntro {
    public static void main(String[] args) {
        int a = 10, b = 0;
        try {
            int c = a / b;
            System.out.println(c);
        } catch (ArithmeticException e) {
            System.out.println("cannot divide by zero");
        }

        int arr[] = {1, 2, 3};
        try {
            System.out.println(arr[5]);
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("exception : " + e.getMessage());
        } finally {
            System.out.println("finally block always runs");
        }

        System.out.println("program did not crash");
    }
}
