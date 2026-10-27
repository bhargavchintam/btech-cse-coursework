/* Lab Program 10
   Create a user defined exception InvalidAgeException. Read the age of a
   person and throw the exception if age is less than 18. Demonstrate
   try, catch and finally.
   javac Lab10_ExceptionDemo.java && java Lab10_ExceptionDemo */

import java.util.Scanner;

class InvalidAgeException extends Exception {
    InvalidAgeException(String msg) {
        super(msg);
    }
}

class Lab10_ExceptionDemo {
    static void checkAge(int age) throws InvalidAgeException {
        if(age < 18)
            throw new InvalidAgeException("age " + age + " is less than 18, not eligible");
        System.out.println("age " + age + " is valid, eligible to vote");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter age: ");
        int age = sc.nextInt();

        try {
            checkAge(age);
        }
        catch(InvalidAgeException e) {
            System.out.println("Caught: " + e.getMessage());
        }
        finally {
            System.out.println("finally block always runs");
        }
    }
}
