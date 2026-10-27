/* Lab Program 8
   Create an abstract class Shape with an abstract method area(). Derive
   Circle, Triangle and Rectangle from it and display the areas using a
   single Shape reference.
   javac Lab08_ShapeInheritance.java && java Lab08_ShapeInheritance */

abstract class Shape {
    abstract double area();
}

class Circle extends Shape {
    double r;
    Circle(double r) { this.r = r; }
    double area() {
        return Math.PI * r * r;
    }
}

class Triangle extends Shape {
    double b, h;
    Triangle(double b, double h) { this.b = b; this.h = h; }
    double area() {
        return 0.5 * b * h;
    }
}

class Rectangle extends Shape {
    double l, w;
    Rectangle(double l, double w) { this.l = l; this.w = w; }
    double area() {
        return l * w;
    }
}

class Lab08_ShapeInheritance {
    public static void main(String[] args) {
        Shape shapes[] = { new Circle(7), new Triangle(6, 4), new Rectangle(5, 3) };
        // same reference calls a different area() each time
        for(int i = 0; i < shapes.length; i++)
            System.out.println("Area = " + shapes[i].area());
    }
}
