// final class cannot be extended, thats why String cant have a subclass

class Base {
    final int MAX = 100;

    final void show() {
        System.out.println("final method cannot be overridden");
    }
}

class Derived extends Base {
    void display() {
        System.out.println("MAX = " + MAX);
    }
}

public class FinalKeyword {
    public static void main(String args[]) {
        Derived d = new Derived();
        d.show();
        d.display();
    }
}
