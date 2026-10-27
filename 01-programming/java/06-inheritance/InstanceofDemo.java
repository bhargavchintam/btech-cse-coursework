class Fruit {
}

class Mango extends Fruit {
}

public class InstanceofDemo {
    public static void main(String[] args) {
        Fruit f = new Mango();

        System.out.println("f instanceof Mango : " + (f instanceof Mango));
        System.out.println("f instanceof Fruit : " + (f instanceof Fruit));

        String str = "hello";
        System.out.println("str instanceof String : " + (str instanceof String));

        if (f instanceof Mango) {
            Mango m = (Mango) f;
            System.out.println("downcast is safe now");
        }
    }
}
