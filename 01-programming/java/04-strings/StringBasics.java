// string basic methods
import java.util.Scanner;

public class StringBasics {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String str = sc.nextLine();

        System.out.println("Length = " + str.length());
        System.out.println("First character = " + str.charAt(0));
        System.out.println("Last character = " + str.charAt(str.length() - 1));
        System.out.println("Index of 'a' = " + str.indexOf('a'));
        System.out.println("Substring from index 2 = " + str.substring(2));
        System.out.println("Substring(1,4) = " + str.substring(1, 4));
    }
}
