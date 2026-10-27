// lambda expressions - new feature in java 8
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class LambdaIntro {
    public static void main(String[] args) {
        Runnable r = () -> System.out.println("no need to write full run() method");
        r.run();

        ArrayList<String> names = new ArrayList<>();
        names.add("Suresh");
        names.add("Anil");
        names.add("Bhargava");
        names.add("Ravi");

        Collections.sort(names, (a, b) -> a.compareTo(b));
        System.out.println("sorted : " + names);

        Comparator<String> byLen = (s1, s2) -> s1.length() - s2.length();
        Collections.sort(names, byLen);
        System.out.println("by length : " + names);
    }
}
