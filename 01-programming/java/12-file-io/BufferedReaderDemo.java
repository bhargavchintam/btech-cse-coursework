// reading a file line by line using BufferedReader
import java.io.*;

public class BufferedReaderDemo {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("data.txt"));
        String line;
        int count = 0;

        while((line = br.readLine()) != null) {
            count++;
            System.out.println(count + " : " + line);
        }
        br.close();
    }
}
