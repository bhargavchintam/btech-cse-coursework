import java.util.ArrayList;
import java.util.Scanner;

public class BankAccount {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        ArrayList<String> statement = new ArrayList<>();
        double balance = 0;
        int tno = 0;

        System.out.print("enter account holder name : ");
        String name = in.next();
        System.out.print("enter account number : ");
        int accno = in.nextInt();
        System.out.println("Welcome " + name);
        System.out.println();

        while (true) {
            System.out.println("1. Deposit");
            System.out.println("2. Withdraw");
            System.out.println("3. Check balance");
            System.out.println("4. Mini statement");
            System.out.println("5. Exit");
            System.out.print("enter choice : ");
            int ch = in.nextInt();

            switch (ch) {
                case 1:
                    System.out.print("enter amount to deposit : ");
                    double d = in.nextDouble();
                    if (d <= 0) {
                        System.out.println("invalid amount");
                    } else {
                        balance = balance + d;
                        tno++;
                        statement.add(tno + ". Deposited Rs." + d + "  balance = " + balance);
                        System.out.println("Rs." + d + " deposited successfully");
                    }
                    break;

                case 2:
                    System.out.print("enter amount to withdraw : ");
                    double w = in.nextDouble();
                    if (w <= 0) {
                        System.out.println("invalid amount");
                    } else if (w > balance) {
                        System.out.println("Insufficient balance");
                        System.out.println("available balance is Rs." + balance);
                    } else {
                        balance = balance - w;
                        tno++;
                        statement.add(tno + ". Withdrawn Rs." + w + "  balance = " + balance);
                        System.out.println("Rs." + w + " withdrawn successfully");
                    }
                    break;

                case 3:
                    System.out.println("Account no : " + accno);
                    System.out.println("Holder : " + name);
                    System.out.println("Current balance = Rs." + balance);
                    break;

                case 4:
                    if (statement.size() == 0) {
                        System.out.println("no transactions yet");
                    } else {
                        System.out.println("Mini statement for a/c " + accno);
                        int start = statement.size() - 5;
                        if (start < 0) {
                            start = 0;
                        }
                        for (int i = start; i < statement.size(); i++) {
                            System.out.println(statement.get(i));
                        }
                    }
                    break;

                case 5:
                    System.out.println("Thank you for banking with us");
                    System.exit(0);

                default:
                    System.out.println("wrong choice");
            }
            System.out.println();
        }
    }
}
