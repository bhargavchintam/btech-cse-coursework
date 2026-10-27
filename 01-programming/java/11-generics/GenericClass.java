// generic class example
class Box<T> {
    T item;

    void set(T item) {
        this.item = item;
    }

    T get() {
        return item;
    }
}

public class GenericClass {
    public static void main(String[] args) {
        Box<Integer> b1 = new Box<>();
        b1.set(100);
        System.out.println("Integer box : " + b1.get());

        Box<String> b2 = new Box<>();
        b2.set("hello");
        System.out.println("String box : " + b2.get());

        Box<Double> b3 = new Box<>();
        b3.set(3.14);
        System.out.println("Double box : " + b3.get());
    }
}
