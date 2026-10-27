import java.util.Arrays;

class Student implements Comparable<Student> {
    String name;
    int marks;

    Student(String name, int marks) {
        this.name = name;
        this.marks = marks;
    }

    public int compareTo(Student s) {
        return this.marks - s.marks;
    }

    public String toString() {
        return name + " " + marks;
    }
}

public class ComparableStudent {
    public static void main(String[] args) {
        Student[] arr = new Student[3];
        arr[0] = new Student("ravi", 85);
        arr[1] = new Student("kiran", 72);
        arr[2] = new Student("bhargav", 91);

        //System.out.println(arr[0].compareTo(arr[1]));
        Arrays.sort(arr);

        for (int i = 0; i < arr.length; i++) {
            System.out.println(arr[i]);
        }
    }
}
