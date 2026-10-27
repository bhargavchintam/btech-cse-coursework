import java.io.*;
import java.net.*;

public class SocketClient {
    public static void main(String[] args) throws IOException {
        Socket s = new Socket("localhost", 5000);
        //System.out.println("connected");

        PrintWriter pw = new PrintWriter(s.getOutputStream(), true);
        BufferedReader br = new BufferedReader(new InputStreamReader(s.getInputStream()));

        pw.println("hello server");
        String reply = br.readLine();
        System.out.println("server replied : " + reply);

        s.close();
    }
}
