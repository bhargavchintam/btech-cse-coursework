// this keyword example

class Employee {
    int id;
    String name;

    Employee(int id, String name) {
        this.id = id;
        this.name = name;
    }

    void display() {
        System.out.println(id + " " + name);
    }
}

public class ThisKeyword {
    public static void main(String[] args) {
        Employee e1 = new Employee(1, "Kumar");
        Employee e2 = new Employee(2, "Priya");

        e1.display();
        e2.display();
    }
}
