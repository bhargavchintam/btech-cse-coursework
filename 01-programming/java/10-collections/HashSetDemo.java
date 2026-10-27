import java.util.HashSet;

public class HashSetDemo {
    public static void main(String[] args) {
        HashSet<String> hs = new HashSet<>();

        hs.add("red");
        hs.add("green");
        hs.add("blue");
        hs.add("red");    // duplicate is ignored
        hs.add("green");

        System.out.println("Set : " + hs);
        System.out.println("Size = " + hs.size());

        hs.remove("blue");
        System.out.println("After remove : " + hs);
        System.out.println("contains red ? " + hs.contains("red"));
    }
}
