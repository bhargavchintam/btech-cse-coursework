import java.util.Scanner;

// character type check
class CharCheck {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("enter a character : ");
        char ch = sc.next().charAt(0);

        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
                System.out.println("vowel");
            else
                System.out.println("consonant");
        } else if (ch >= '0' && ch <= '9') {
            System.out.println("digit");
        } else {
            System.out.println("special character");
        }
    }
}
