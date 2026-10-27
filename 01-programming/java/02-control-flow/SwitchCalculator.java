// simple calculator using switch case
import java.util.Scanner;

public class SwitchCalculator {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter two numbers");
        double a = sc.nextDouble();
        double b = sc.nextDouble();
        System.out.println("Enter operator (+ - * /)");
        char op = sc.next().charAt(0);

        switch (op) {
            case '+':
                System.out.println("Result = " + (a + b));
                break;
            case '-':
                System.out.println("Result = " + (a - b));
                break;
            case '*':
                System.out.println("Result = " + (a * b));
                break;
            case '/':
                if (b == 0)
                    System.out.println("cannot divide by zero");
                else
                    System.out.println("Result = " + (a / b));
                break;
            default:
                System.out.println("Invalid operator");
        }
    }
}
