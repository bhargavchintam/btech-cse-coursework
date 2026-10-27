// student record system using arraylist

import java.util.ArrayList;
import java.util.Scanner;

class Student {
    int roll;
    String name;
    double marks;

    Student(int roll, String name, double marks) {
        this.roll = roll;
        this.name = name;
        this.marks = marks;
    }

    void display() {
        System.out.println(roll + "\t" + name + "\t" + marks);
    }
}

public class StudentRecordSystem {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Student> list = new ArrayList<>();

        while (true) {
            System.out.println("1. Add student");
            System.out.println("2. Display all");
            System.out.println("3. Search by roll no");
            System.out.println("4. Delete student");
            System.out.println("5. Exit");
            System.out.print("Enter choice: ");
            int ch = sc.nextInt();

            switch (ch) {
                case 1:
                    System.out.print("Enter roll no: ");
                    int r = sc.nextInt();
                    System.out.print("Enter name: ");
                    String nm = sc.next();
                    System.out.print("Enter marks: ");
                    double m = sc.nextDouble();
                    list.add(new Student(r, nm, m));
                    System.out.println("Student added");
                    break;

                case 2:
                    if (list.size() == 0) {
                        System.out.println("No records to display");
                    } else {
                        System.out.println("Roll\tName\tMarks");
                        for (int i = 0; i < list.size(); i++) {
                            list.get(i).display();
                        }
                        System.out.println("Total students: " + list.size());
                    }
                    break;

                case 3:
                    System.out.print("Enter roll no to search: ");
                    int sr = sc.nextInt();
                    boolean found = false;
                    for (int i = 0; i < list.size(); i++) {
                        if (list.get(i).roll == sr) {
                            System.out.println("Record found");
                            System.out.println("Roll\tName\tMarks");
                            list.get(i).display();
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        System.out.println("Record not found");
                    }
                    break;

                case 4:
                    System.out.print("Enter roll no to delete: ");
                    int dr = sc.nextInt();
                    boolean del = false;
                    for (int i = 0; i < list.size(); i++) {
                        if (list.get(i).roll == dr) {
                            list.remove(i);
                            del = true;
                            break;
                        }
                    }
                    if (del) {
                        System.out.println("Record deleted");
                    } else {
                        System.out.println("Record not found");
                    }
                    break;

                case 5:
                    System.out.println("Exiting...");
                    System.exit(0);

                default:
                    System.out.println("Invalid choice");
            }
            System.out.println();
        }
    }
}
