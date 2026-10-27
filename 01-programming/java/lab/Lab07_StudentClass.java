/* Lab Program 7
   Create a class Student with roll number, name and marks. Read n
   students using a constructor and display the details.
   javac Lab07_StudentClass.java && java Lab07_StudentClass */

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

class Lab07_StudentClass {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of students: ");
        int n = sc.nextInt();

        Student s[] = new Student[n];
        for(int i = 0; i < n; i++) {
            System.out.println("Enter roll name marks of student " + (i + 1));
            s[i] = new Student(sc.nextInt(), sc.next(), sc.nextDouble());
        }

        System.out.println("Roll\tName\tMarks");
        for(int i = 0; i < n; i++)
            s[i].display();
    }
}
