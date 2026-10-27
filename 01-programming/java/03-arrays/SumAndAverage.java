import java.util.Scanner;

public class SumAndAverage {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("enter n : ");
        int n = in.nextInt();
        int a[] = new int[n];
        System.out.println("enter elements");
        int sum = 0;
        for(int i = 0; i < n; i++) {
            a[i] = in.nextInt();
            sum = sum + a[i];
        }

        double avg = (double)sum / n;
        System.out.println("Sum = " + sum);
        System.out.printf("Average = %.2f\n", avg);
    }
}
