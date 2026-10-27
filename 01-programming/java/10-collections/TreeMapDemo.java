import java.util.TreeMap;

// treemap keeps keys in sorted order
public class TreeMapDemo {
    public static void main(String args[]) {
        TreeMap<String, Integer> tm = new TreeMap<>();

        tm.put("maths", 85);
        tm.put("java", 92);
        tm.put("dbms", 78);
        tm.put("os", 88);

        System.out.println("TreeMap : " + tm);
        System.out.println("Marks in java : " + tm.get("java"));

        System.out.println("First key : " + tm.firstKey());
        System.out.println("Last key : " + tm.lastKey());

        for (String sub : tm.keySet()) {
            System.out.println(sub + " : " + tm.get(sub));
        }
    }
}
