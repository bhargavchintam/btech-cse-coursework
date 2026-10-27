// generics - type is checked at compile time itself
class Box<T> {
    T item;

    void set(T x) {
        item = x;
    }

    T get() {
        return item;
    }
}

public class GenericsIntro {
    public static void main(String[] args) {
        Box<Integer> b1 = new Box<>();
        b1.set(100);
        System.out.println("integer box : " + b1.get());

        Box<String> b2 = new Box<>();
        b2.set("hello generics");
        System.out.println("string box : " + b2.get());

        Box<Double> b3 = new Box<>();
        b3.set(45.6);
        System.out.println("double box : " + b3.get());
    }
}
