// program to add two numbers using text fields
import javax.swing.*;
import java.awt.event.*;

public class TextFieldDemo implements ActionListener {
    JFrame f;
    JTextField t1, t2;
    JButton b;
    JLabel l;

    TextFieldDemo() {
        f = new JFrame("Addition");
        t1 = new JTextField();
        t2 = new JTextField();
        b = new JButton("Add");
        l = new JLabel("Result: ");

        t1.setBounds(50, 50, 150, 30);
        t2.setBounds(50, 100, 150, 30);
        b.setBounds(50, 150, 100, 30);
        l.setBounds(50, 200, 200, 30);

        b.addActionListener(this);

        f.add(t1);
        f.add(t2);
        f.add(b);
        f.add(l);
        f.setLayout(null);
        f.setSize(300, 320);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        int n1 = Integer.parseInt(t1.getText());
        int n2 = Integer.parseInt(t2.getText());
        l.setText("Result: " + (n1 + n2));
    }

    public static void main(String[] args) {
        new TextFieldDemo();
    }
}
