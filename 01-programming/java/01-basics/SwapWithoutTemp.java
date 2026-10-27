import java.util.Scanner;

public class SwapWithoutTemp {
    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        System.out.println("enter two numbers");
        int a = s.nextInt();
        int b = s.nextInt();

        System.out.println("before swap a = " + a + " b = " + b);
        a = a + b;
        b = a - b;
        a = a - b;
        System.out.println("after swap a = " + a + " b = " + b);
    }
}
