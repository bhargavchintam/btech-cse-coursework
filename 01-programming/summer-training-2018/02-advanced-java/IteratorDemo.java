import java.util.ArrayList;
import java.util.Iterator;

public class IteratorDemo {
    public static void main(String[] args) {
        ArrayList<Integer> list = new ArrayList<>();
        list.add(10);
        list.add(15);
        list.add(20);
        list.add(25);
        list.add(30);

        Iterator<Integer> it = list.iterator();
        while (it.hasNext()) {
            int x = it.next();
            if (x % 2 != 0) {
                it.remove();
            }
        }
        System.out.println("only even left : " + list);
    }
}
