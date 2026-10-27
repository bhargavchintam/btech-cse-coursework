import java.util.Scanner;

public class TryWithResources {
    public static void main(String[] args) {
        // scanner gets closed automatically
        try (Scanner sc = new Scanner(System.in)) {
            System.out.print("Enter name: ");
            String name = sc.nextLine();
            System.out.print("Enter age: ");
            int age = sc.nextInt();
            System.out.println(name + " is " + age + " years old");
        }
    }
}
