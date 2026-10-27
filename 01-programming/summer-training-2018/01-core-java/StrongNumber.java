import java.util.Scanner;

// strong number check
class StrongNumber {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("enter a number : ");
        int n = sc.nextInt();
        int temp = n;
        int sum = 0;

        while (temp > 0) {
            int d = temp % 10;
            int fact = 1;
            for (int i = 1; i <= d; i++) {
                fact = fact * i;
            }
            sum = sum + fact;
            temp = temp / 10;
        }

        if (sum == n)
            System.out.println(n + " is a strong number");
        else
            System.out.println(n + " is not a strong number");
    }
}
