import java.util.Scanner;

public class ScannerInput {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter age: ");
        int age = sc.nextInt();
        System.out.print("Enter marks: ");
        double marks = sc.nextDouble();
        sc.nextLine(); // nextInt leaves the enter key in buffer so nextLine reads empty without this
        System.out.print("Enter name: ");
        String name = sc.nextLine();
        System.out.println("Name : " + name);
        System.out.println("Age : " + age);
        System.out.println("Marks : " + marks);
    }
}
