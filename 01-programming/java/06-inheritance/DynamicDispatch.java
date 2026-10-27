class A {
    void callme() {
        System.out.println("inside A callme");
    }
}

class B extends A {
    void callme() {
        System.out.println("inside B callme");
    }
}

public class DynamicDispatch {
    public static void main(String[] args) {
        A ref;

        ref = new A();
        ref.callme();

        ref = new B();
        ref.callme(); // child method runs even though reference is of parent type
    }
}
