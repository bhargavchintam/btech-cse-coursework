import java.util.ArrayList;

// program to demonstrate arraylist methods
public class ArrayListDemo {
    public static void main(String[] args) {
        ArrayList<String> list = new ArrayList<>();

        list.add("apple");
        list.add("banana");
        list.add("mango");
        list.add("grapes");

        System.out.println("List : " + list);
        System.out.println("Size = " + list.size());
        System.out.println("Element at index 2 : " + list.get(2));

        list.remove("banana");
        System.out.println("After remove : " + list);
        System.out.println("Size = " + list.size());

        System.out.println("contains mango ? " + list.contains("mango"));
        System.out.println("contains banana ? " + list.contains("banana"));
    }
}
