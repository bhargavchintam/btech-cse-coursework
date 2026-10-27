// count lines words and characters in a file
import java.io.*;

public class CountWordsFile {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("data.txt"));
        String line;
        int lines = 0, words = 0, chars = 0;

        while((line = br.readLine()) != null) {
            //System.out.println(line);
            lines++;
            chars = chars + line.length();
            String w[] = line.split(" ");
            words = words + w.length;
        }
        br.close();

        System.out.println("Lines = " + lines);
        System.out.println("Words = " + words);
        System.out.println("Characters = " + chars);
    }
}
