import java.util.Scanner;

abstract class Shape {
    abstract double area();
}

class Circle extends Shape {
    double r;

    Circle(double r) {
        this.r = r;
    }

    double area() {
        return 3.14 * r * r;
    }
}

class Rectangle extends Shape {
    double l, b;

    Rectangle(double l, double b) {
        this.l = l;
        this.b = b;
    }

    double area() {
        return l * b;
    }
}

public class AbstractClassDemo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("enter radius : ");
        double r = sc.nextDouble();
        System.out.print("enter length and breadth : ");
        double l = sc.nextDouble();
        double b = sc.nextDouble();

        Shape s1 = new Circle(r);
        Shape s2 = new Rectangle(l, b);
        System.out.println("area of circle = " + s1.area());
        System.out.println("area of rectangle = " + s2.area());
    }
}
