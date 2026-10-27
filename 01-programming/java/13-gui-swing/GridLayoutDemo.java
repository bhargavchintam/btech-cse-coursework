// grid layout - calculator style buttons
import javax.swing.*;
import java.awt.*;

public class GridLayoutDemo {
    public static void main(String args[]) {
        JFrame f = new JFrame("GridLayout Demo");
        f.setLayout(new GridLayout(4, 4));

        String btns[] = {"7", "8", "9", "/", "4", "5", "6", "*", "1", "2", "3", "-", "0", ".", "=", "+"};
        for(int i = 0; i < btns.length; i++) {
            f.add(new JButton(btns[i]));
        }

        f.setSize(300, 300);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setVisible(true);
    }
}
