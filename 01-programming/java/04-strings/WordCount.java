// count words in a sentence
import java.util.Scanner;

public class WordCount {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter a sentence: ");
        String str = in.nextLine();

        String words[] = str.trim().split("\\s+");
        System.out.println("Number of words = " + words.length);
    }
}
