class Grandfather {
    void land() {
        System.out.println("grandfather has land");
    }
}

class Father extends Grandfather {
    void house() {
        System.out.println("father has house");
    }
}

class Son extends Father {
    void bike() {
        System.out.println("son has bike");
    }
}

public class MultilevelInheritance {
    public static void main(String args[]) {
        Son s = new Son();
        s.land();
        s.house();
        s.bike();
    }
}
