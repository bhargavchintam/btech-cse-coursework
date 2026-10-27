// palindrome number check
import java.util.Scanner;

public class PalindromeNumber {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int n = sc.nextInt();

        int temp = n, rev = 0;
        while (temp != 0) {
            rev = rev * 10 + temp % 10;
            temp = temp / 10;
        }

        if (rev == n)
            System.out.println(n + " is a palindrome");
        else
            System.out.println(n + " is not a palindrome");
    }
}
