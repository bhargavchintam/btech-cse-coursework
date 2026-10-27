// sorting objects using comparator lambda
import java.util.ArrayList;
import java.util.Collections;

class Student {
    String name;
    int age;
    Student(String name, int age) {
        this.name = name;
        this.age = age;
    }
    public String toString() {
        return name + "(" + age + ")";
    }
}

public class SortByAge {
    public static void main(String[] args) {
        ArrayList<Student> list = new ArrayList<>();
        list.add(new Student("ravi", 21));
        list.add(new Student("bhargava", 19));
        list.add(new Student("suresh", 23));
        list.add(new Student("anil", 20));

        Collections.sort(list, (a, b) -> a.age - b.age);
        System.out.println("by age : " + list);

        Collections.sort(list, (a, b) -> a.name.compareTo(b.name));
        System.out.println("by name : " + list);
    }
}
