// method overloading
class OverloadDemo {
    static int area(int side) {
        return side * side;
    }

    static int area(int l, int b) {
        return l * b;
    }

    static double area(double r) {
        return 3.14 * r * r;
    }

    public static void main(String[] args) {
        System.out.println("square area = " + area(5));
        System.out.println("rectangle area = " + area(4, 6));
        System.out.println("circle area = " + area(3.0));
    }
}
