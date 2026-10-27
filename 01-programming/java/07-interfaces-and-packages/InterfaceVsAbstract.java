// interface all methods abstract by default, abstract class can have both

abstract class Phone {
    abstract void ring();

    void charge() {
        System.out.println("phone is charging");
    }
}

class Nokia extends Phone {
    void ring() {
        System.out.println("nokia ringtone");
    }
}

interface Camera {
    void click();
}

class DigitalCamera implements Camera {
    public void click() {
        System.out.println("photo clicked");
    }
}

public class InterfaceVsAbstract {
    public static void main(String[] args) {
        Nokia n = new Nokia();
        n.ring();
        n.charge();

        DigitalCamera d = new DigitalCamera();
        d.click();
    }
}
