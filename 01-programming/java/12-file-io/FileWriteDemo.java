// program to write data to a file using FileWriter
import java.io.*;

public class FileWriteDemo {
    public static void main(String[] args) {
        try {
            FileWriter fw = new FileWriter("data.txt");
            fw.write("Java is a platform independent language\n");
            fw.write("File handling in java is done using java.io package\n");
            fw.write("This is the third line\n");
            fw.close();
            System.out.println("Data written to data.txt");
        } catch(IOException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}
