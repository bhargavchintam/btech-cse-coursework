/* Bindu Bhargava  14-09-18 */
import java.util.Scanner;

public class MatrixAddition {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter rows and columns: ");
        int m = sc.nextInt();
        int n = sc.nextInt();
        int a[][] = new int[m][n];
        int b[][] = new int[m][n];
        int c[][] = new int[m][n];

        System.out.println("Enter elements of first matrix:");
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                a[i][j] = sc.nextInt();

        System.out.println("Enter elements of second matrix:");
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                b[i][j] = sc.nextInt();

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                c[i][j] = a[i][j] + b[i][j];

        System.out.println("Sum of matrices:");
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++)
                System.out.print(c[i][j] + " ");
            System.out.println();
        }
    }
}
