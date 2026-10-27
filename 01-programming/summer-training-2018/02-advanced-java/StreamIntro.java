import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class StreamIntro {
    public static void main(String[] args) {
        List<String> names = new ArrayList<>();
        names.add("Bhargava");
        names.add("Ravi");
        names.add("Suresh");
        names.add("Anil");
        names.add("Ramesh");
        names.add("Kiran");

        List<String> rnames = names.stream()
                .filter(s -> s.startsWith("R"))
                .collect(Collectors.toList());
        System.out.println("starting with R : " + rnames);

        List<String> upper = names.stream()
                .map(s -> s.toUpperCase())
                .collect(Collectors.toList());
        System.out.println("uppercase : " + upper);

        long n = names.stream().filter(s -> s.length() > 4).count();
        System.out.println("names longer than 4 letters : " + n);
    }
}
