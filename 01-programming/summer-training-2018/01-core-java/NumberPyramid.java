import java.util.Scanner;

// number pyramid pattern
class NumberPyramid {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("enter rows : ");
        int n = in.nextInt();

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                System.out.print(j + " ");
            }
            System.out.println();
        }
    }
}
