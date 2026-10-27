/* Lab Program 2
   Write a Java program to perform arithmetic operations on two numbers
   using switch case. The operator is read as a character.
   javac Lab02_Calculator.java && java Lab02_Calculator */

import java.util.Scanner;

class Lab02_Calculator {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter two numbers: ");
        double a = sc.nextDouble();
        double b = sc.nextDouble();
        System.out.print("Enter operator (+ - * /): ");
        char op = sc.next().charAt(0);

        switch(op) {
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
                if(b == 0)
                    System.out.println("cannot divide by zero");
                else
                    System.out.println("Result = " + (a / b));
                break;
            default:
                System.out.println("Invalid operator");
        }
    }
}
