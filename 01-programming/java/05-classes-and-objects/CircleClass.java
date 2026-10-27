import java.util.Scanner;

// circle area and circumference using class

public class CircleClass {
    double r;

    double area() {
        return 3.14159 * r * r;
    }

    double circumference() {
        return 2 * 3.14159 * r;
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("enter radius : ");
        CircleClass c = new CircleClass();
        c.r = sc.nextDouble();

        System.out.println("Area = " + c.area());
        System.out.println("Circumference = " + c.circumference());
    }
}
