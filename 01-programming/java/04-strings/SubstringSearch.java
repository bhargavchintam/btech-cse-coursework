import java.util.Scanner;

public class SubstringSearch {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter main string: ");
        String str = sc.nextLine();
        System.out.print("Enter substring to search: ");
        String sub = sc.nextLine();

        if(str.contains(sub))
            System.out.println(sub + " found at index " + str.indexOf(sub));
        else
            System.out.println(sub + " not found");
    }
}
