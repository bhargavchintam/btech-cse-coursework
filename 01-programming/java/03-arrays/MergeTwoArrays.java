// program to merge two arrays
import java.util.Scanner;

public class MergeTwoArrays {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter size of first array: ");
        int m = sc.nextInt();
        int a[] = new int[m];
        System.out.println("Enter elements of first array:");
        for(int i = 0; i < m; i++)
            a[i] = sc.nextInt();

        System.out.print("Enter size of second array: ");
        int n = sc.nextInt();
        int b[] = new int[n];
        System.out.println("Enter elements of second array:");
        for(int i = 0; i < n; i++)
            b[i] = sc.nextInt();

        int c[] = new int[m + n];
        for(int i = 0; i < m; i++)
            c[i] = a[i];
        for(int i = 0; i < n; i++)
            c[m + i] = b[i];

        System.out.println("Merged array:");
        for(int i = 0; i < m + n; i++)
            System.out.print(c[i] + " ");
        System.out.println();
    }
}
