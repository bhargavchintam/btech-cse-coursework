import java.util.Scanner;

public class StringMethods {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String str = in.nextLine();

        System.out.println("Uppercase: " + str.toUpperCase());
        System.out.println("Trimmed: " + str.trim());
        System.out.println("Replace a with *: " + str.replace('a', '*'));

        String words[] = str.split(" ");
        System.out.println("Words in the string:");
        for(int i = 0; i < words.length; i++)
            System.out.println(words[i]);
    }
}
