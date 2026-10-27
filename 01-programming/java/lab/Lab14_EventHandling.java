/* Lab Program 14
   Write a Java Swing program to demonstrate event handling. Clicking the
   button changes the text of a label.
   javac Lab14_EventHandling.java && java Lab14_EventHandling */

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class Lab14_EventHandling {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Event Handling");
        frame.setSize(300, 150);
        frame.setLayout(new FlowLayout());
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        final JLabel label = new JLabel("Button not clicked yet");
        JButton btn = new JButton("Click Me");

        btn.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                label.setText("Button was clicked");
            }
        });

        frame.add(btn);
        frame.add(label);
        frame.setVisible(true);
    }
}
