import java.util.Scanner;

public class NumberFormatDemo {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        String str = sc.nextLine();

        try {
            int n = Integer.parseInt(str);
            System.out.println("Square = " + n * n);
        } catch (NumberFormatException e) {
            System.out.println("invalid number " + e.getMessage());
        }
    }
}
