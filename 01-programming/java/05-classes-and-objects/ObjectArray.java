import java.util.Scanner;

// array of student objects

class Student {
    int roll;
    String name;
    double marks;
}

public class ObjectArray {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter number of students: ");
        int n = in.nextInt();

        Student st[] = new Student[n];

        for (int i = 0; i < n; i++) {
            st[i] = new Student();
            System.out.println("Enter roll, name and marks of student " + (i + 1));
            st[i].roll = in.nextInt();
            st[i].name = in.next();
            st[i].marks = in.nextDouble();
            //System.out.println("read student " + i);
        }

        System.out.println("Roll\tName\tMarks");
        for (int i = 0; i < n; i++) {
            System.out.println(st[i].roll + "\t" + st[i].name + "\t" + st[i].marks);
        }
    }
}
