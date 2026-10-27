import java.util.Scanner;

public class PrimeCheck {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Enter a number");
        int n = in.nextInt();
        int flag = 0;

        for (int i = 2; i <= n / 2; i++) {
            //System.out.println("checking " + i);
            if (n % i == 0) {
                flag = 1;
                break;
            }
        }

        if (n <= 1)
            flag = 1;

        if (flag == 0)
            System.out.println(n + " is a prime number");
        else
            System.out.println(n + " is not a prime number");
    }
}
