// hashmap stores key value pairs
import java.util.HashMap;

public class MapIntro {
    public static void main(String[] args) {
        HashMap<Integer, String> map = new HashMap<>();
        map.put(101, "Bhargava");
        map.put(102, "Ravi");
        map.put(103, "Suresh");
        map.put(104, "Kiran");

        System.out.println(map);
        System.out.println("roll 102 : " + map.get(102));

        map.remove(103);
        System.out.println("after remove : " + map);

        for (Integer k : map.keySet()) {
            System.out.println(k + " -> " + map.get(k));
        }

        System.out.println("contains 101 ? " + map.containsKey(101));
        System.out.println("total entries : " + map.size());
    }
}
