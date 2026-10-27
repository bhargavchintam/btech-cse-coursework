// count vowels consonants digits and spaces
import java.util.Scanner;

public class CountVowels {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String str = in.nextLine();

        int v = 0, c = 0, d = 0, sp = 0;
        for(int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'
                || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
                v++;
            else if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
                c++;
            else if(ch >= '0' && ch <= '9')
                d++;
            else if(ch == ' ')
                sp++;
        }

        System.out.println("Vowels = " + v);
        System.out.println("Consonants = " + c);
        System.out.println("Digits = " + d);
        System.out.println("Spaces = " + sp);
    }
}
