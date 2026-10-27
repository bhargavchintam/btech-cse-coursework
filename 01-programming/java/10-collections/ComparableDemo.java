import java.util.ArrayList;
import java.util.Collections;

// sorting objects using comparable interface
class Student implements Comparable<Student> {
    int rno;
    String name;
    int marks;

    Student(int rno, String name, int marks) {
        this.rno = rno;
        this.name = name;
        this.marks = marks;
    }

    public int compareTo(Student s) {
        return this.marks - s.marks;
    }
}

public class ComparableDemo {
    public static void main(String[] args) {
        ArrayList<Student> list = new ArrayList<>();
        list.add(new Student(1, "Ravi", 78));
        list.add(new Student(2, "Amit", 92));
        list.add(new Student(3, "Kiran", 65));
        list.add(new Student(4, "Suma", 84));

        Collections.sort(list);

        System.out.println("Students sorted by marks :");
        for (Student s : list) {
            System.out.println(s.rno + " " + s.name + " " + s.marks);
        }
    }
}
