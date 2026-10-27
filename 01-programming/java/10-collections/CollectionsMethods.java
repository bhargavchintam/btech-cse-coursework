import java.util.ArrayList;
import java.util.Collections;

public class CollectionsMethods {
    public static void main(String[] args) {
        ArrayList<Integer> list = new ArrayList<>();
        list.add(45);
        list.add(12);
        list.add(89);
        list.add(3);
        list.add(67);

        System.out.println("Original list : " + list);

        Collections.sort(list);
        System.out.println("Sorted : " + list);

        Collections.reverse(list);
        System.out.println("Reversed : " + list);

        Collections.shuffle(list);
        System.out.println("Shuffled : " + list);

        System.out.println("Max = " + Collections.max(list));
        System.out.println("Min = " + Collections.min(list));
    }
}
