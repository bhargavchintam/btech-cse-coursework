import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

class Emp {
    int id;
    String name;
    int sal;

    Emp(int id, String name, int sal) {
        this.id = id;
        this.name = name;
        this.sal = sal;
    }
}

class NameComparator implements Comparator<Emp> {
    public int compare(Emp e1, Emp e2) {
        return e1.name.compareTo(e2.name);
    }
}

public class ComparatorDemo {
    public static void main(String[] args) {
        ArrayList<Emp> list = new ArrayList<>();
        list.add(new Emp(3, "Ravi", 45000));
        list.add(new Emp(1, "Amit", 52000));
        list.add(new Emp(2, "Kiran", 38000));

        Collections.sort(list, new NameComparator());
        System.out.println("Sorted by name :");
        for (Emp e : list) {
            System.out.println(e.id + " " + e.name + " " + e.sal);
        }

        // java 8 lambda way, sir showed this in class
        Collections.sort(list, (e1, e2) -> e1.sal - e2.sal);
        System.out.println("Sorted by salary :");
        for (Emp e : list) {
            System.out.println(e.id + " " + e.name + " " + e.sal);
        }
    }
}
