// writing to a file using BufferedWriter
import java.io.*;

public class BufferedWriterDemo {
    public static void main(String args[]) {
        try {
            BufferedWriter bw = new BufferedWriter(new FileWriter("notes.txt"));
            bw.write("BufferedWriter is faster than FileWriter");
            bw.newLine();
            bw.write("because it writes to a buffer first");
            bw.newLine();
            bw.write("and flushes when the buffer is full");
            bw.newLine();
            bw.close();
            System.out.println("done writing to notes.txt");
        } catch(IOException e) {
            System.out.println(e.getMessage());
        }
    }
}
