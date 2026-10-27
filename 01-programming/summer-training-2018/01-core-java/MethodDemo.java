// methods in java
class MethodDemo {
    static int add(int a, int b) {
        return a + b;
    }

    static int square(int n) {
        return n * n;
    }

    static void greet(String name) {
        System.out.println("Hello " + name);
    }

    public static void main(String[] args) {
        int sum = add(10, 20);
        System.out.println("sum = " + sum);
        System.out.println("square of 6 = " + square(6));
        greet("Bhargava");
    }
}
