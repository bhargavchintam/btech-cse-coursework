// default methods were added in java 8

interface Calculator {
    int add(int a, int b);

    default int square(int n) {
        return n * n;
    }
}

class MyCalc implements Calculator {
    public int add(int a, int b) {
        return a + b;
    }
}

public class DefaultMethodDemo {
    public static void main(String[] args) {
        MyCalc c = new MyCalc();
        System.out.println("add(5,3) = " + c.add(5, 3));
        System.out.println("square(4) = " + c.square(4));
    }
}
