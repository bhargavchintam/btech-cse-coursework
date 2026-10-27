// toggle case using char arithmetic
import java.util.Scanner;

public class ToggleCase {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.print("enter a string : ");
        String str = s.nextLine();

        String res = "";
        for(int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);
            if(ch >= 'a' && ch <= 'z')
                ch = (char)(ch - 32);
            else if(ch >= 'A' && ch <= 'Z')
                ch = (char)(ch + 32);
            res = res + ch;
        }

        System.out.println("toggled string : " + res);
    }
}
