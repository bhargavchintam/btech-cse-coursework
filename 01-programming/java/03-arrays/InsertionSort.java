// insertion sort
import java.util.Scanner;

public class InsertionSort {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter n: ");
        int n = in.nextInt();
        int a[] = new int[n];
        System.out.println("Enter elements:");
        for(int i = 0; i < n; i++)
            a[i] = in.nextInt();

        for(int i = 1; i < n; i++) {
            int key = a[i];
            int j = i - 1;
            while(j >= 0 && a[j] > key) {
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = key;
        }

        System.out.println("Sorted array:");
        for(int i = 0; i < n; i++)
            System.out.print(a[i] + " ");
        System.out.println();
    }
}
