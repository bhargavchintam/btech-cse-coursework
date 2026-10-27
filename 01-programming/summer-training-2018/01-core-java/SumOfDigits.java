import java.util.Scanner;

// sum of digits
class SumOfDigits {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.print("enter a number : ");
        int n = s.nextInt();
        int sum = 0;

        while (n > 0) {
            int d = n % 10;
            sum = sum + d;
            n = n / 10;
        }
        System.out.println("sum of digits = " + sum);
    }
}
