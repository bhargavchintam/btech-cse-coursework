// transpose of a matrix
import java.util.Scanner;

public class MatrixTranspose {
    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        System.out.print("enter rows and columns : ");
        int m = s.nextInt();
        int n = s.nextInt();
        int a[][] = new int[m][n];
        System.out.println("enter elements");
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                a[i][j] = s.nextInt();

        int t[][] = new int[n][m];
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                t[j][i] = a[i][j];

        System.out.println("transpose is");
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++)
                System.out.print(t[i][j] + " ");
            System.out.println();
        }
    }
}
