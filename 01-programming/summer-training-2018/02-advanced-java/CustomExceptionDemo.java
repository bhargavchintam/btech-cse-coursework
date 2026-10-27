/* user defined exception */
class InvalidAgeException extends Exception {
    InvalidAgeException(String msg) {
        super(msg);
    }
}

public class CustomExceptionDemo {
    static void checkAge(int age) throws InvalidAgeException {
        if (age < 18) {
            throw new InvalidAgeException("age " + age + " not valid for voting");
        }
        System.out.println("age " + age + " is valid, can vote");
    }

    public static void main(String[] args) {
        try {
            checkAge(21);
            checkAge(15);
        } catch (InvalidAgeException e) {
            System.out.println("caught : " + e.getMessage());
        }
    }
}
