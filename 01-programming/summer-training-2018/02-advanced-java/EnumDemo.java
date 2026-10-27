// enum can have fields and constructor
enum Coin {
    PENNY(1), NICKEL(5), DIME(10), QUARTER(25);

    private int value;
    Coin(int value) {
        this.value = value;
    }
    int getValue() {
        return value;
    }
}

public class EnumDemo {
    public static void main(String[] args) {
        int total = 0;
        for (Coin c : Coin.values()) {
            System.out.println(c + " = " + c.getValue() + " cents");
            total = total + c.getValue();
        }
        System.out.println("total = " + total + " cents");
    }
}
