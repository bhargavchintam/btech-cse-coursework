// menu bar with menus and menu items
import javax.swing.*;
import java.awt.event.*;

public class MenuDemo {
    public static void main(String[] args) {
        JFrame f = new JFrame("Menu Demo");
        JMenuBar mb = new JMenuBar();
        JMenu file = new JMenu("File");
        JMenu edit = new JMenu("Edit");
        JMenuItem open = new JMenuItem("Open");
        JMenuItem save = new JMenuItem("Save");
        JMenuItem exit = new JMenuItem("Exit");

        exit.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });

        file.add(open);
        file.add(save);
        file.addSeparator();
        file.add(exit);
        mb.add(file);
        mb.add(edit);

        f.setJMenuBar(mb);
        f.setSize(400, 300);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setVisible(true);
    }
}
