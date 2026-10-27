/* method overriding example */
class Bank {
    int getRate() {
        return 0;
    }
}

class SBI extends Bank {
    int getRate() {
        return 8;
    }
}

class ICICI extends Bank {
    int getRate() {
        return 7;
    }
}

class OverrideDemo {
    public static void main(String[] args) {
        Bank b;
        b = new SBI();
        System.out.println("SBI rate of interest: " + b.getRate());
        b = new ICICI();
        System.out.println("ICICI rate of interest: " + b.getRate());
    }
}
