import java.util.Scanner;

// ternary operator
class TernaryDemo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("enter two numbers : ");
        int a = sc.nextInt();
        int b = sc.nextInt();

        int max = (a > b) ? a : b;
        System.out.println("max = " + max);

        String res = (a % 2 == 0) ? "even" : "odd";
        System.out.println(a + " is " + res);
    }
}
