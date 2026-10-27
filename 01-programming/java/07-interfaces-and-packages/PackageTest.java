// user defined package demo

import mypack.*;

public class PackageTest {
    public static void main(String[] args) {
        MsgUtil.greet("bhargav");
        System.out.println("max of 12 and 8 = " + MathUtil.max(12, 8));
        System.out.println("factorial of 5 = " + MathUtil.factorial(5));
        MsgUtil.bye();
    }
}
