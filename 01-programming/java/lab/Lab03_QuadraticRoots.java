/* Lab Program 3
   Write a Java program to find the roots of a quadratic equation using
   the Scanner class. Handle imaginary roots also.
   javac Lab03_QuadraticRoots.java && java Lab03_QuadraticRoots */

import java.util.Scanner;

class Lab03_QuadraticRoots {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a b c: ");
        double a = sc.nextDouble();
        double b = sc.nextDouble();
        double c = sc.nextDouble();

        double d = b * b - 4 * a * c;

        if(d > 0) {
            double r1 = (-b + Math.sqrt(d)) / (2 * a);
            double r2 = (-b - Math.sqrt(d)) / (2 * a);
            System.out.println("Roots are real and distinct");
            System.out.println("r1 = " + r1);
            System.out.println("r2 = " + r2);
        }
        else if(d == 0) {
            double r = -b / (2 * a);
            System.out.println("Roots are real and equal");
            System.out.println("r1 = r2 = " + r);
        }
        else {
            double rp = -b / (2 * a);
            double ip = Math.sqrt(-d) / (2 * a);
            System.out.println("Roots are imaginary");
            System.out.println("r1 = " + rp + " + " + ip + "i");
            System.out.println("r2 = " + rp + " - " + ip + "i");
        }
    }
}
