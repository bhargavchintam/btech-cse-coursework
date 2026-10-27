import java.util.Scanner;

// gcd of two numbers
class GcdDemo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("enter two numbers : ");
        int a = sc.nextInt();
        int b = sc.nextInt();

        while (a != b) {
            if (a > b)
                a = a - b;
            else
                b = b - a;
        }
        System.out.println("gcd = " + a);
    }
}
