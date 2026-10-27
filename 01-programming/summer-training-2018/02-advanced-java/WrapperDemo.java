import java.util.ArrayList;
import java.util.Scanner;

public class WrapperDemo {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("how many numbers : ");
        int n = in.nextInt();

        ArrayList<Integer> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int x = in.nextInt();
            list.add(x);          // autoboxing int to Integer
        }

        int sum = 0;
        for (int val : list) {    // unboxing Integer to int
            sum = sum + val;
        }
        System.out.println("sum = " + sum);
        System.out.println("max value of int = " + Integer.MAX_VALUE);
    }
}
