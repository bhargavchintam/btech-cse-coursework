// program to copy a file using byte streams
import java.io.*;

public class CopyFileDemo {
    public static void main(String[] args) {
        try {
            FileInputStream fin = new FileInputStream("data.txt");
            FileOutputStream fout = new FileOutputStream("copy.txt");
            int b;
            while((b = fin.read()) != -1) {
                fout.write(b);
            }
            fin.close();
            fout.close();
            System.out.println("File copied to copy.txt");
        } catch(IOException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}
