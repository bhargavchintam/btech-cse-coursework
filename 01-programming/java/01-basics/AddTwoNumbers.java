import java.util.Scanner;

public class AddTwoNumbers {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Enter two numbers");
        int a = in.nextInt();
        int b = in.nextInt();
        int sum = a + b;
        System.out.println("Sum = " + sum);
    }
}
