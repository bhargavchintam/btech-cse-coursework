// button click event using ActionListener
import javax.swing.*;
import java.awt.event.*;

public class ButtonEvent {
    JFrame f;
    JButton b;
    JLabel l;

    ButtonEvent() {
        f = new JFrame("Button Event");
        b = new JButton("Click Me");
        l = new JLabel("Button not clicked yet");
        l.setBounds(120, 60, 200, 30);
        b.setBounds(130, 120, 120, 40);

        b.addActionListener(new MyListener());

        f.add(b);
        f.add(l);
        f.setLayout(null);
        f.setSize(400, 300);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setVisible(true);
    }

    class MyListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            l.setText("Button was clicked");
        }
    }

    public static void main(String[] args) {
        new ButtonEvent();
    }
}
