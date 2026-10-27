// interface example

interface Shape {
    double area();
}

class Circle implements Shape {
    double r;

    Circle(double r) {
        this.r = r;
    }

    public double area() {
        return 3.14 * r * r;
    }
}

class Square implements Shape {
    double side;

    Square(double side) {
        this.side = side;
    }

    public double area() {
        return side * side;
    }
}

public class InterfaceBasics {
    public static void main(String[] args) {
        Shape s = new Circle(7);
        System.out.println("area of circle = " + s.area());

        s = new Square(4);
        System.out.println("area of square = " + s.area());
    }
}
