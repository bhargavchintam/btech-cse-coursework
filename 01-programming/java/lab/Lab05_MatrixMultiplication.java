/* Lab Program 5
   Write a Java program to multiply two matrices. Check whether the
   matrices are compatible for multiplication.
   javac Lab05_MatrixMultiplication.java && java Lab05_MatrixMultiplication */

import java.util.Scanner;

class Lab05_MatrixMultiplication {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter rows and cols of A: ");
        int m = sc.nextInt();
        int n = sc.nextInt();
        System.out.print("Enter rows and cols of B: ");
        int p = sc.nextInt();
        int q = sc.nextInt();

        if(n != p) {
            System.out.println("Multiplication not possible");
            return;
        }

        int a[][] = new int[m][n];
        int b[][] = new int[p][q];
        int c[][] = new int[m][q];

        System.out.println("Enter elements of A");
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                a[i][j] = sc.nextInt();

        System.out.println("Enter elements of B");
        for(int i = 0; i < p; i++)
            for(int j = 0; j < q; j++)
                b[i][j] = sc.nextInt();

        for(int i = 0; i < m; i++)
            for(int j = 0; j < q; j++)
                for(int k = 0; k < n; k++)
                    c[i][j] += a[i][k] * b[k][j];

        System.out.println("Product matrix:");
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < q; j++)
                System.out.print(c[i][j] + " ");
            System.out.println();
        }
    }
}
