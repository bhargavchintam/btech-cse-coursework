/* Bindu Bhargava  03-11-18 */
import java.util.HashMap;

public class HashMapDemo {
    public static void main(String[] args) {
        HashMap<Integer, String> hm = new HashMap<>();

        hm.put(101, "Ravi");
        hm.put(102, "Amit");
        hm.put(103, "Kiran");
        hm.put(104, "Suma");

        System.out.println("Map : " + hm);
        System.out.println("Value for key 102 : " + hm.get(102));
        System.out.println("Value for key 105 : " + hm.get(105));

        for (Integer key : hm.keySet()) {
            System.out.println(key + " -> " + hm.get(key));
        }

        hm.remove(103);
        System.out.println("After remove : " + hm);
        System.out.println("Size = " + hm.size());
    }
}
