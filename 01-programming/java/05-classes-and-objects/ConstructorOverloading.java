// constructor overloading using box class

class Box {
    double l, b, h;

    Box() {
        l = b = h = 1;
    }

    Box(double side) {
        l = b = h = side;
    }

    Box(double l1, double b1, double h1) {
        l = l1;
        b = b1;
        h = h1;
    }

    double volume() {
        return l * b * h;
    }
}

public class ConstructorOverloading {
    public static void main(String[] args) {
        Box b1 = new Box();
        Box b2 = new Box(5);
        Box b3 = new Box(2, 3, 4);

        System.out.println("Volume of b1 = " + b1.volume());
        System.out.println("Volume of b2 = " + b2.volume());
        System.out.println("Volume of b3 = " + b3.volume());
    }
}
