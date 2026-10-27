import java.io.*;

public class FileWriteRead {
    public static void main(String args[]) throws IOException {  // have to catch or declare
        FileWriter fw = new FileWriter("notes.txt");
        fw.write("java summer training\n");
        fw.write("file handling using FileWriter\n");
        fw.write("reading back with BufferedReader\n");
        fw.close();
        System.out.println("file written");

        BufferedReader br = new BufferedReader(new FileReader("notes.txt"));
        String line;
        while ((line = br.readLine()) != null) {
            System.out.println(line);
        }
        br.close();
    }
}
