/* Bindu Bhargava  12-10-18 */

class Bank {
    double getRate() {
        return 0;
    }
}

class SBI extends Bank {
    double getRate() {
        return 8.4;
    }
}

class HDFC extends Bank {
    double getRate() {
        return 7.3;
    }
}

public class MethodOverriding {
    public static void main(String[] args) {
        SBI s = new SBI();
        HDFC h = new HDFC();
        System.out.println("SBI rate of interest = " + s.getRate());
        System.out.println("HDFC rate of interest = " + h.getRate());
    }
}
