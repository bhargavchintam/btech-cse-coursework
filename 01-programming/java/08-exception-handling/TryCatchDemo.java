// program to demonstrate divide by zero exception
import java.util.Scanner;

public class TryCatchDemo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter two numbers: ");
        int a = sc.nextInt();
        int b = sc.nextInt();

        try {
            int c = a / b;
            System.out.println("Result = " + c);
        } catch (ArithmeticException e) {
            System.out.println("cannot divide by zero");
        }
        System.out.println("End of program");
    }
}
