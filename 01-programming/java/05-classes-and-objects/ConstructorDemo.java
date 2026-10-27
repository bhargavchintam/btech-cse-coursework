// default and parameterized constructor

class Student1 {
    int id;
    String name;

    Student1() {
        id = 0;
        name = "unknown";
    }

    Student1(int i, String n) {
        id = i;
        name = n;
    }

    void display() {
        System.out.println(id + " " + name);
    }
}

public class ConstructorDemo {
    public static void main(String[] args) {
        Student1 s1 = new Student1();
        Student1 s2 = new Student1(101, "Ravi");

        s1.display();
        s2.display();
    }
}
