class Employee {
    String name;

    Employee(String name) {
        this.name = name;
    }

    void details() {
        System.out.println("name : " + name);
    }
}

interface Payable {
    void salary();
}

class Manager extends Employee implements Payable {
    Manager(String name) {
        super(name);
    }

    public void salary() {
        System.out.println("salary : 50000");
    }
}

public class ExtendVsImplement {
    public static void main(String[] args) {
        Manager m = new Manager("ramesh");
        m.details();
        m.salary();
    }
}
