/* Bindu Bhargava  17-11-18 */
// serialization - writing an object to a file
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

public class SerializationDemo {
    public static void main(String[] args) {
        Student s1 = new Student(101, "Bhargava", 87.5);
        try {
            FileOutputStream fos = new FileOutputStream("student.ser");
            ObjectOutputStream oos = new ObjectOutputStream(fos);
            oos.writeObject(s1);
            oos.close();
            fos.close();
            System.out.println("Object saved to student.ser");
        } catch(IOException e) {
            System.out.println(e.getMessage());
        }
    }
}
