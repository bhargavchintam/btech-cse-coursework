// encapsulation with private fields and getters setters

class Account {
    private int accno;
    private double balance;

    public void setAccno(int a) {
        accno = a;
    }

    public int getAccno() {
        return accno;
    }

    public void setBalance(double b) {
        balance = b;
    }

    public double getBalance() {
        return balance;
    }
}

public class EncapsulationDemo {
    public static void main(String[] args) {
        Account a = new Account();
        a.setAccno(1234);
        a.setBalance(5000.50);

        System.out.println("Account no = " + a.getAccno());
        System.out.println("Balance = " + a.getBalance());
    }
}
