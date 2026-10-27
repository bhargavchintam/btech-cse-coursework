/* Bindu Bhargava  14-07-18 */
import java.io.*;
import java.net.*;

public class SocketServer {
    public static void main(String args[]) throws IOException {
        ServerSocket ss = new ServerSocket(5000);
        System.out.println("server waiting on port 5000...");

        Socket s = ss.accept();
        BufferedReader br = new BufferedReader(new InputStreamReader(s.getInputStream()));
        PrintWriter pw = new PrintWriter(s.getOutputStream(), true);

        String msg = br.readLine();
        System.out.println("client : " + msg);
        pw.println("echo : " + msg);

        s.close();
        ss.close();
    }
}
