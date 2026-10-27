import java.util.Scanner;
import java.util.StringTokenizer;

public class TokenizerDemo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("enter a sentence : ");
        String line = sc.nextLine();

        StringTokenizer st = new StringTokenizer(line, " ");
        System.out.println("total words : " + st.countTokens());
        while (st.hasMoreTokens()) {
            System.out.println(st.nextToken());
        }
    }
}
