import java.util.Scanner;

public class MatrixCalculator {
    static Scanner in = new Scanner(System.in);

    public static void main(String args[]) {
        while (true) {
            System.out.println("1. Add matrices");
            System.out.println("2. Subtract matrices");
            System.out.println("3. Multiply matrices");
            System.out.println("4. Transpose");
            System.out.println("5. Exit");
            System.out.print("enter choice : ");
            int ch = in.nextInt();

            switch (ch) {
                case 1:
                case 2:
                    System.out.print("enter rows and cols of first matrix : ");
                    int r1 = in.nextInt();
                    int c1 = in.nextInt();
                    System.out.print("enter rows and cols of second matrix : ");
                    int r2 = in.nextInt();
                    int c2 = in.nextInt();

                    if (r1 != r2 || c1 != c2) {
                        System.out.println("dimensions must be same for add/subtract");
                        break;
                    }

                    System.out.println("first matrix :");
                    int a[][] = readMatrix(r1, c1);
                    System.out.println("second matrix :");
                    int b[][] = readMatrix(r2, c2);

                    int res[][] = new int[r1][c1];
                    for (int i = 0; i < r1; i++) {
                        for (int j = 0; j < c1; j++) {
                            if (ch == 1) {
                                res[i][j] = a[i][j] + b[i][j];
                            } else {
                                res[i][j] = a[i][j] - b[i][j];
                            }
                        }
                    }

                    if (ch == 1) {
                        System.out.println("sum of the matrices :");
                    } else {
                        System.out.println("difference of the matrices :");
                    }
                    printMatrix(res);
                    break;

                case 3:
                    System.out.print("enter rows and cols of first matrix : ");
                    int m1 = in.nextInt();
                    int n1 = in.nextInt();
                    System.out.print("enter rows and cols of second matrix : ");
                    int m2 = in.nextInt();
                    int n2 = in.nextInt();

                    if (n1 != m2) {
                        System.out.println("cannot multiply, cols of first must equal rows of second");
                        break;
                    }

                    System.out.println("first matrix :");
                    int p[][] = readMatrix(m1, n1);
                    System.out.println("second matrix :");
                    int q[][] = readMatrix(m2, n2);

                    int prod[][] = new int[m1][n2];
                    for (int i = 0; i < m1; i++) {
                        for (int j = 0; j < n2; j++) {
                            prod[i][j] = 0;
                            for (int k = 0; k < n1; k++) {
                                prod[i][j] = prod[i][j] + p[i][k] * q[k][j];
                            }
                        }
                    }

                    System.out.println("product of the matrices :");
                    printMatrix(prod);
                    break;

                case 4:
                    System.out.print("enter rows and cols of the matrix : ");
                    int r = in.nextInt();
                    int c = in.nextInt();
                    int t[][] = readMatrix(r, c);

                    int trans[][] = new int[c][r];
                    for (int i = 0; i < r; i++) {
                        for (int j = 0; j < c; j++) {
                            trans[j][i] = t[i][j];
                        }
                    }

                    System.out.println("transpose :");
                    printMatrix(trans);
                    break;

                case 5:
                    System.out.println("bye");
                    System.exit(0);

                default:
                    System.out.println("wrong choice");
            }
            System.out.println();
        }
    }

    static int[][] readMatrix(int r, int c) {
        int m[][] = new int[r][c];
        System.out.println("enter " + (r * c) + " elements :");
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                m[i][j] = in.nextInt();
            }
        }
        return m;
    }

    static void printMatrix(int m[][]) {
        for (int i = 0; i < m.length; i++) {
            for (int j = 0; j < m[0].length; j++) {
                System.out.print(m[i][j] + " ");
            }
            System.out.println();
        }
    }
}
