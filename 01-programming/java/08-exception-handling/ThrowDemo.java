/* throw keyword example */
import java.util.Scanner;

public class ThrowDemo {
    static void checkAge(int age) {
        if (age < 18) {
            throw new ArithmeticException("not eligible to vote");
        } else {
            System.out.println("eligible to vote");
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("enter age : ");
        int age = in.nextInt();

        try {
            checkAge(age);
        } catch (ArithmeticException e) {
            System.out.println("Exception caught: " + e.getMessage());
        }
    }
}
