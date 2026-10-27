import java.util.ArrayList;
import java.util.List;

// wildcard ? accepts list of any type
public class WildcardDemo {
    static void printList(List<?> list) {
        for (Object o : list) {
            System.out.print(o + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        List<Integer> nums = new ArrayList<>();
        nums.add(1);
        nums.add(2);
        nums.add(3);

        List<String> names = new ArrayList<>();
        names.add("ravi");
        names.add("amit");

        List<Double> vals = new ArrayList<>();
        vals.add(1.5);
        vals.add(2.5);

        printList(nums);
        printList(names);
        printList(vals);
    }
}
