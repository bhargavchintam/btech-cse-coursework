// email and phone validation using regex
import java.util.Scanner;
import java.util.regex.Pattern;

public class RegexDemo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("enter email : ");
        String email = sc.nextLine();
        if (Pattern.matches("[a-zA-Z0-9._]+@[a-zA-Z0-9]+\\.[a-z]{2,}", email)) {
            System.out.println("valid email");
        } else {
            System.out.println("invalid email");
        }

        System.out.print("enter phone : ");
        String phone = sc.nextLine();
        if (Pattern.matches("[6-9][0-9]{9}", phone)) {
            System.out.println("valid phone number");
        } else {
            System.out.println("invalid phone number");
        }
    }
}
