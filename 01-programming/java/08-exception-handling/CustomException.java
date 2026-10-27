/* Bindu Bhargava  14-10-18 */
import java.util.Scanner;

class InvalidMarksException extends Exception {
    InvalidMarksException(String msg) {
        super(msg);
    }
}

public class CustomException {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter marks: ");
        int marks = sc.nextInt();

        try {
            if (marks < 0 || marks > 100)
                throw new InvalidMarksException("marks should be between 0 and 100");
            System.out.println("Marks entered = " + marks);
        } catch (InvalidMarksException e) {
            System.out.println("Exception: " + e.getMessage());
        }
    }
}
