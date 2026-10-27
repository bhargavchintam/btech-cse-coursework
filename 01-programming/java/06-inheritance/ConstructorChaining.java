// order of constructor calls in inheritance

class One {
    One() {
        System.out.println("One constructor");
    }
}

class Two extends One {
    Two() {
        System.out.println("Two constructor");
    }
}

class Three extends Two {
    Three() {
        System.out.println("Three constructor");
    }
}

public class ConstructorChaining {
    public static void main(String[] args) {
        Three t = new Three();
    }
}
