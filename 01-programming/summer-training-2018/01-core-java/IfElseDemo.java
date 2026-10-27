import java.util.Scanner;

class IfElseDemo {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("enter a number : ");
        int n = in.nextInt();

        if (n > 0) {
            System.out.println("positive");
        } else if (n < 0) {
            System.out.println("negative");
        } else {
            System.out.println("zero");
        }

        if (n % 2 == 0)
            System.out.println("even");
        else
            System.out.println("odd");
    }
}
