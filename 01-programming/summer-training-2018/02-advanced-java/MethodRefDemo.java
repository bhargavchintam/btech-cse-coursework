// method reference using ::
import java.util.ArrayList;
import java.util.Collections;

public class MethodRefDemo {
    static void greet() {
        System.out.println("hello from static method");
    }

    public static void main(String[] args) {
        Runnable r = MethodRefDemo::greet;
        r.run();

        ArrayList<String> names = new ArrayList<>();
        names.add("Ravi");
        names.add("Anil");
        names.add("Bhargava");

        names.forEach(System.out::println);

        Collections.sort(names, String::compareTo);
        System.out.println("sorted : " + names);
    }
}
