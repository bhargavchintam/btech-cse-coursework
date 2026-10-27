// program to display information about a file using File class
import java.io.File;

public class FileInfoDemo {
    public static void main(String[] args) {
        File f = new File("data.txt");

        if(f.exists()) {
            System.out.println("Name: " + f.getName());
            System.out.println("Path: " + f.getAbsolutePath());
            System.out.println("Size: " + f.length() + " bytes");
            System.out.println("Is directory: " + f.isDirectory());
            System.out.println("Can read: " + f.canRead());
            System.out.println("Can write: " + f.canWrite());
        } else {
            System.out.println("file does not exist");
        }
    }
}
