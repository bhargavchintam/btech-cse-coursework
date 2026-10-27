public class NestedClassDemo {
    static int count = 0;

    static class Box {
        int l, b;
        Box(int l, int b) {
            this.l = l;
            this.b = b;
            count++;
        }
        int area() {
            return l * b;
        }
    }

    public static void main(String[] args) {
        Box b1 = new Box(4, 5);
        Box b2 = new Box(3, 6);
        System.out.println("area 1 : " + b1.area());
        System.out.println("area 2 : " + b2.area());
        System.out.println("boxes created : " + count);
    }
}
