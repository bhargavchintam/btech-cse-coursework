// deserialization - reading the object back from the file
import java.io.*;

class Student implements Serializable {
    int roll;
    String name;
    double marks;

    Student(int r, String n, double m) {
        roll = r;
        name = n;
        marks = m;
    }
}

public class DeserializationDemo {
    public static void main(String[] args) {
        try {
            FileInputStream fis = new FileInputStream("student.ser");
            ObjectInputStream ois = new ObjectInputStream(fis);
            Student s = (Student)ois.readObject();
            ois.close();
            System.out.println("Roll: " + s.roll);
            System.out.println("Name: " + s.name);
            System.out.println("Marks: " + s.marks);
        } catch(Exception e) {
            // readObject can throw ClassNotFoundException also
            System.out.println(e);
        }
    }
}
