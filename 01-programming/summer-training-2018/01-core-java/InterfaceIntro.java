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

class Rectangle implements Shape {
    double l, b;

    Rectangle(double l, double b) {
        this.l = l;
        this.b = b;
    }

    public double area() {
        return l * b;
    }
}

class InterfaceIntro {
    public static void main(String[] args) {
        Shape s1 = new Circle(5);
        Shape s2 = new Rectangle(4, 6);
        System.out.println("circle area = " + s1.area());
        System.out.println("rectangle area = " + s2.area());
    }
}
