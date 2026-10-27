// first swing program - creating a window
import javax.swing.*;

public class FirstFrame {
    public static void main(String[] args) {
        JFrame f = new JFrame("My First Frame");
        f.setSize(400, 300);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setVisible(true);
    }
}
