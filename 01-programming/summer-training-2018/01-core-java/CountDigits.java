import java.util.Scanner;

// count number of digits
class CountDigits {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("enter a number : ");
        int n = in.nextInt();
        int count = 0;

        while (n > 0) {
            count++;
            n = n / 10;
        }
        System.out.println("number of digits = " + count);
    }
}
