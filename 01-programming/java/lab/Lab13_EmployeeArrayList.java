/* Lab Program 13
   Store Employee objects (id, name, salary) in an ArrayList. Display all
   employees, search by id and sort them by salary using a Comparator.
   javac Lab13_EmployeeArrayList.java && java Lab13_EmployeeArrayList */

import java.util.*;

class Employee {
    int id;
    String name;
    double salary;

    Employee(int id, String name, double salary) {
        this.id = id;
        this.name = name;
        this.salary = salary;
    }

    void display() {
        System.out.println(id + "\t" + name + "\t" + salary);
    }
}

class SalaryComparator implements Comparator<Employee> {
    public int compare(Employee e1, Employee e2) {
        if(e1.salary < e2.salary) return -1;
        if(e1.salary > e2.salary) return 1;
        return 0;
    }
}

class Lab13_EmployeeArrayList {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Employee> list = new ArrayList<Employee>();

        System.out.print("Enter number of employees: ");
        int n = sc.nextInt();
        for(int i = 0; i < n; i++) {
            System.out.println("Enter id name salary of employee " + (i + 1));
            list.add(new Employee(sc.nextInt(), sc.next(), sc.nextDouble()));
        }

        System.out.println("Id\tName\tSalary");
        for(Employee e : list)
            e.display();

        System.out.print("Enter id to search: ");
        int key = sc.nextInt();
        boolean found = false;
        for(Employee e : list) {
            if(e.id == key) {
                System.out.print("Found: ");
                e.display();
                found = true;
            }
        }
        if(!found)
            System.out.println("id " + key + " not found");

        Collections.sort(list, new SalaryComparator());
        System.out.println("Sorted by salary:");
        for(Employee e : list)
            e.display();
    }
}
