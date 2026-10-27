// swapping two numbers using temp variable
import java.util.Scanner;

public class SwapNumbers {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a and b");
        int a = sc.nextInt();
        int b = sc.nextInt();

        System.out.println("Before swap a = " + a + " b = " + b);
        int temp = a;
        a = b;
        b = temp;
        System.out.println("After swap a = " + a + " b = " + b);
    }
}
