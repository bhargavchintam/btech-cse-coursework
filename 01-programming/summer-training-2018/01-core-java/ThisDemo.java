class Employee {
    String name;
    int salary;

    Employee(String name, int salary) {
        this.name = name; // this refers to current object
        this.salary = salary;
    }

    void show() {
        System.out.println(name + " earns " + salary);
    }
}

class ThisDemo {
    public static void main(String[] args) {
        Employee e1 = new Employee("Suresh", 25000);
        Employee e2 = new Employee("Ramesh", 30000);
        e1.show();
        e2.show();
    }
}
