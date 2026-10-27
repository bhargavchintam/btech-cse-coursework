class Book {
    String name;

    Book(String name) {
        this.name = name;
    }
}

class Student {
    int id;
    String name;

    Student(int id, String name) {
        this.id = id;
        this.name = name;
    }

    public String toString() {
        return id + " " + name;
    }
}

public class ToStringDemo {
    public static void main(String[] args) {
        Book b = new Book("java complete reference");
        System.out.println(b); // without override it prints classname@hashcode

        Student s = new Student(45, "bhargav");
        System.out.println(s);
    }
}
