// flow layout arranges components one after another
import javax.swing.*;
import java.awt.*;

public class FlowLayoutDemo {
    public static void main(String[] args) {
        JFrame f = new JFrame("FlowLayout Demo");
        f.setLayout(new FlowLayout());

        f.add(new JButton("One"));
        f.add(new JButton("Two"));
        f.add(new JButton("Three"));
        f.add(new JButton("Four"));
        f.add(new JButton("Five"));

        f.setSize(300, 200);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setVisible(true);
    }
}
