import java.util.ArrayList;
import java.util.Iterator;
import java.util.ListIterator;

public class IteratorDemo {
    public static void main(String[] args) {
        ArrayList<Integer> list = new ArrayList<>();
        list.add(10);
        list.add(20);
        list.add(30);
        list.add(40);
        list.add(50);

        Iterator<Integer> it = list.iterator();
        System.out.println("Using iterator :");
        while (it.hasNext()) {
            System.out.println(it.next());
        }

        ListIterator<Integer> lit = list.listIterator(list.size());
        System.out.println("In reverse using ListIterator :");
        while (lit.hasPrevious()) {
            System.out.println(lit.previous());
        }
    }
}
