import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class ScannerFileDemo {
    public static void main(String args[]) throws IOException {
        FileWriter fw = new FileWriter("cities.txt");
        fw.write("bangalore\n");
        fw.write("mysore\n");
        fw.write("hubli\n");
        fw.close();

        Scanner s = new Scanner(new File("cities.txt"));
        int count = 0;
        while (s.hasNextLine()) {
            System.out.println(s.nextLine());
            count++;
        }
        s.close();
        System.out.println("total lines : " + count);
    }
}
