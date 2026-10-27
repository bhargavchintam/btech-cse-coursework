class Parent {
    int x = 10;

    Parent() {
        System.out.println("parent constructor");
    }

    void show() {
        System.out.println("parent show()");
    }
}

class Child extends Parent {
    int x = 20;

    Child() {
        super(); // super must be first line
        System.out.println("child constructor");
    }

    void show() {
        System.out.println("child show()");
    }

    void display() {
        System.out.println("x = " + x);
        System.out.println("super.x = " + super.x);
        show();
        super.show();
    }
}

public class SuperKeyword {
    public static void main(String[] args) {
        Child c = new Child();
        c.display();
    }
}
