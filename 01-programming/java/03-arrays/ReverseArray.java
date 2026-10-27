import java.util.Scanner;

public class ReverseArray {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter n: ");
        int n = s.nextInt();
        int a[] = new int[n];
        System.out.println("Enter elements:");
        for(int i = 0; i < n; i++)
            a[i] = s.nextInt();

        int temp;
        for(int i = 0; i < n / 2; i++) {
            temp = a[i];
            a[i] = a[n - 1 - i];
            a[n - 1 - i] = temp;
        }

        System.out.println("Reversed array:");
        for(int i = 0; i < n; i++)
            System.out.print(a[i] + " ");
        System.out.println();
    }
}
