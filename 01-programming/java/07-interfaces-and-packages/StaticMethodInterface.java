// static method is called with interface name not object

interface MathOp {
    static int cube(int n) {
        return n * n * n;
    }
}

public class StaticMethodInterface {
    public static void main(String args[]) {
        System.out.println("cube of 3 = " + MathOp.cube(3));
        System.out.println("cube of 5 = " + MathOp.cube(5));
    }
}
