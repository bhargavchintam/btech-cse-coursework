import java.util.ArrayList;
import java.util.ListIterator;

public class ListIteratorDemo {
    public static void main(String[] args) {
        ArrayList<String> list = new ArrayList<>();
        list.add("a");
        list.add("b");
        list.add("c");

        ListIterator<String> it = list.listIterator();
        while (it.hasNext()) {
            String s = it.next();
            it.set(s.toUpperCase());
        }
        System.out.println("forward : " + list);

        // listiterator can move backward also
        System.out.print("backward : ");
        while (it.hasPrevious()) {
            System.out.print(it.previous() + " ");
        }
        System.out.println();
    }
}
