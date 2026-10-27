// bounded type parameter, T must be a Number
public class BoundedType {
    static <T extends Number> double sum(T a, T b) {
        return a.doubleValue() + b.doubleValue();
    }

    public static void main(String args[]) {
        System.out.println("Sum of ints = " + sum(10, 20));
        System.out.println("Sum of doubles = " + sum(2.5, 3.7));
        System.out.println("Sum of int and double = " + sum(5, 5));

        //sum("a", "b");  gives compile error since String is not Number
    }
}
