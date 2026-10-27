// anonymous object example

class Rectangle2 {
    int l, b;

    Rectangle2(int l, int b) {
        this.l = l;
        this.b = b;
    }

    int area() {
        return l * b;
    }
}

public class AnonymousObjectDemo {
    public static void main(String[] args) {
        System.out.println("Area = " + new Rectangle2(3, 4).area());
        System.out.println("Area = " + new Rectangle2(5, 6).area());
    }
}
