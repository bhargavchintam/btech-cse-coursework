import java.util.Scanner;

// prime number check
class PrimeNumber {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        System.out.print("enter number : ");
        int n = in.nextInt();
        int flag = 0;

        for (int i = 2; i <= n / 2; i++) {
            if (n % i == 0) {
                flag = 1;
                break;
            }
        }

        if (flag == 0 && n > 1)
            System.out.println(n + " is prime");
        else
            System.out.println(n + " is not prime");
    }
}
