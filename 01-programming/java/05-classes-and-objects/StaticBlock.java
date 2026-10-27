// static block example

public class StaticBlock {
    static int x;

    static {
        x = 10;
        System.out.println("static block executed"); // this prints before main!
    }

    public static void main(String args[]) {
        System.out.println("inside main");
        System.out.println("x = " + x);
    }
}
