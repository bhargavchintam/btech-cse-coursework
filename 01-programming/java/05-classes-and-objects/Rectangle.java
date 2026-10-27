/* Bindu Bhargava  03-09-18 */
// program to find area and perimeter of rectangle using class

public class Rectangle {
    int length, breadth;

    int area() {
        return length * breadth;
    }

    int perimeter() {
        return 2 * (length + breadth);
    }

    public static void main(String[] args) {
        Rectangle r1 = new Rectangle();
        Rectangle r2 = new Rectangle();

        r1.length = 10;
        r1.breadth = 5;

        r2.length = 7;
        r2.breadth = 3;

        System.out.println("Area of r1 = " + r1.area());
        System.out.println("Perimeter of r1 = " + r1.perimeter());
        System.out.println("Area of r2 = " + r2.area());
        System.out.println("Perimeter of r2 = " + r2.perimeter());
    }
}
