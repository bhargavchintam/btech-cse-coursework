import java.util.TreeSet;

public class TreeSetDemo {
    public static void main(String[] args) {
        TreeSet<Integer> ts = new TreeSet<>();
        ts.add(50);
        ts.add(20);
        ts.add(80);
        ts.add(20);
        ts.add(10);

        System.out.println(ts);
        System.out.println("smallest : " + ts.first());
        System.out.println("largest : " + ts.last());
        System.out.println("size : " + ts.size());
        System.out.println("contains 80 ? " + ts.contains(80));
    }
}
