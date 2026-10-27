// program to calculate simple interest
import java.util.Scanner;

public class SimpleInterest {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Enter principal, rate and time");
        double p = in.nextDouble();
        double r = in.nextDouble();
        double t = in.nextDouble();

        double si = (p * r * t) / 100;
        System.out.println("Simple Interest = " + si);
    }
}
