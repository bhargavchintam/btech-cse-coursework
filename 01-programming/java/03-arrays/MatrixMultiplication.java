// matrix multiplication with dimension check
import java.util.Scanner;

public class MatrixMultiplication {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter rows and columns of first matrix: ");
        int m = in.nextInt();
        int n = in.nextInt();
        int a[][] = new int[m][n];
        System.out.println("Enter elements of first matrix:");
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                a[i][j] = in.nextInt();

        System.out.print("Enter rows and columns of second matrix: ");
        int p = in.nextInt();
        int q = in.nextInt();

        if(n != p) {
            System.out.println("Multiplication not possible");
            return;
        }

        int b[][] = new int[p][q];
        System.out.println("Enter elements of second matrix:");
        for(int i = 0; i < p; i++)
            for(int j = 0; j < q; j++)
                b[i][j] = in.nextInt();

        int c[][] = new int[m][q];
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < q; j++) {
                c[i][j] = 0;
                for(int k = 0; k < n; k++)
                    c[i][j] = c[i][j] + a[i][k] * b[k][j];
            }
        }

        System.out.println("Product matrix:");
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < q; j++)
                System.out.print(c[i][j] + " ");
            System.out.println();
        }
    }
}
