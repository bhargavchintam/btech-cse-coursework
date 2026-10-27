// try with resources closes the stream automatically
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class TryResourceDemo {
    public static void main(String[] args) throws IOException {
        try (FileWriter fw = new FileWriter("marks.txt")) {
            fw.write("85\n");
            fw.write("90\n");
            fw.write("78\n");
        }

        try (BufferedReader br = new BufferedReader(new FileReader("marks.txt"))) {
            String line;
            int sum = 0;
            while ((line = br.readLine()) != null) {
                sum = sum + Integer.parseInt(line);
            }
            System.out.println("total marks = " + sum);
        }
    }
}
