/* Lab Program 6
   Write a Java program to check whether a string is a palindrome and
   count the number of vowels in it.
   javac Lab06_StringPalindrome.java && java Lab06_StringPalindrome */

import java.util.Scanner;

class Lab06_StringPalindrome {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String str = sc.nextLine();

        String rev = "";
        for(int i = str.length() - 1; i >= 0; i--)
            rev = rev + str.charAt(i);

        if(str.equals(rev))
            System.out.println(str + " is a palindrome");
        else
            System.out.println(str + " is not a palindrome");

        int vowels = 0;
        for(int i = 0; i < str.length(); i++) {
            char ch = Character.toLowerCase(str.charAt(i));
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                vowels++;
        }
        System.out.println("Number of vowels = " + vowels);
    }
}
