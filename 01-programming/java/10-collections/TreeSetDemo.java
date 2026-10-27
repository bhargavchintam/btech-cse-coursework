import java.util.TreeSet;

// treeset stores elements in sorted order automatically
public class TreeSetDemo {
    public static void main(String[] args) {
        TreeSet<Integer> ts = new TreeSet<>();

        ts.add(50);
        ts.add(10);
        ts.add(40);
        ts.add(20);
        ts.add(30);

        System.out.println("TreeSet : " + ts);
        System.out.println("First : " + ts.first());
        System.out.println("Last : " + ts.last());

        TreeSet<String> names = new TreeSet<>();
        names.add("ravi");
        names.add("amit");
        names.add("kiran");
        names.add("bindu");

        System.out.println("Names sorted : " + names);
    }
}
