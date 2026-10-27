// treemap keeps keys in sorted order
import java.util.TreeMap;

public class TreeMapDemo {
    public static void main(String[] args) {
        TreeMap<Integer, String> tm = new TreeMap<>();
        tm.put(105, "kiran");
        tm.put(101, "bhargava");
        tm.put(103, "ravi");
        tm.put(102, "suresh");

        System.out.println(tm);
        System.out.println("first key : " + tm.firstKey());
        System.out.println("last key : " + tm.lastKey());

        for (Integer k : tm.keySet()) {
            System.out.println(k + " -> " + tm.get(k));
        }
    }
}
