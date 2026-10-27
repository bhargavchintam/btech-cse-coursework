import java.util.Scanner;

// fibonacci series
class FibDemo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("how many terms : ");
        int n = sc.nextInt();

        int a = 0, b = 1;
        for (int i = 1; i <= n; i++) {
            System.out.print(a + " ");
            //System.out.println("a=" + a + " b=" + b);
            int c = a + b;
            a = b;
            b = c;
        }
        System.out.println();
    }
}
