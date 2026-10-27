// method overloading with sum

public class MethodOverloading {
    int sum(int a, int b) {
        return a + b;
    }

    int sum(int a, int b, int c) {
        return a + b + c;
    }

    double sum(double a, double b) {
        return a + b;
    }

    public static void main(String[] args) {
        MethodOverloading obj = new MethodOverloading();

        System.out.println("sum of 2 ints = " + obj.sum(10, 20));
        System.out.println("sum of 3 ints = " + obj.sum(10, 20, 30));
        System.out.println("sum of 2 doubles = " + obj.sum(10.5, 20.5));
    }
}
