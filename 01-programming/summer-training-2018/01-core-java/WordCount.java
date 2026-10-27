import java.util.Scanner;

// count words in a sentence
class WordCount {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("enter a sentence : ");
        String str = in.nextLine();

        String words[] = str.split(" ");
        // TODO extra spaces give wrong count
        System.out.println("number of words = " + words.length);
    }
}
