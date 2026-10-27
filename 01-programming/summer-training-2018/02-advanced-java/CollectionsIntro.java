import java.util.ArrayList;

public class CollectionsIntro {
    public static void main(String[] args) {
        ArrayList<String> list = new ArrayList<>();
        list.add("apple");
        list.add("banana");
        list.add("mango");
        list.add("grapes");

        System.out.println(list);
        System.out.println("size : " + list.size());

        list.remove("banana");
        list.add(1, "orange");
        System.out.println("after remove and add : " + list);

        System.out.println("element at 2 : " + list.get(2));
        System.out.println("contains mango ? " + list.contains("mango"));

        for (String s : list) {
            System.out.println(s);
        }
    }
}
