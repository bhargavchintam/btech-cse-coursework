// constructor example
class Student {
    String name;
    int roll;

    Student() {
        System.out.println("default constructor called");
    }

    Student(String n, int r) {
        name = n;
        roll = r;
    }

    void display() {
        System.out.println(roll + " " + name);
    }
}

class ConstructorIntro {
    public static void main(String[] args) {
        Student s1 = new Student();
        Student s2 = new Student("Rahul", 21);
        s2.display();
    }
}
