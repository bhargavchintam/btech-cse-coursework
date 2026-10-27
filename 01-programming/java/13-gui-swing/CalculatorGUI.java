// simple calculator with two numbers and four operations
import javax.swing.*;
import java.awt.event.*;

public class CalculatorGUI implements ActionListener {
    JFrame f;
    JTextField t1, t2;
    JButton add, sub, mul, div;
    JLabel res;

    CalculatorGUI() {
        f = new JFrame("Calculator");
        f.setLayout(null);

        JLabel l1 = new JLabel("First number");
        JLabel l2 = new JLabel("Second number");
        t1 = new JTextField();
        t2 = new JTextField();
        add = new JButton("+");
        sub = new JButton("-");
        mul = new JButton("*");
        div = new JButton("/");
        res = new JLabel("Result = ");

        l1.setBounds(30, 30, 120, 25);
        t1.setBounds(160, 30, 120, 25);
        l2.setBounds(30, 70, 120, 25);
        t2.setBounds(160, 70, 120, 25);
        add.setBounds(30, 120, 55, 30);
        sub.setBounds(95, 120, 55, 30);
        mul.setBounds(160, 120, 55, 30);
        div.setBounds(225, 120, 55, 30);
        res.setBounds(30, 170, 250, 30);

        add.addActionListener(this);
        sub.addActionListener(this);
        mul.addActionListener(this);
        div.addActionListener(this);

        f.add(l1);
        f.add(t1);
        f.add(l2);
        f.add(t2);
        f.add(add);
        f.add(sub);
        f.add(mul);
        f.add(div);
        f.add(res);
        f.setSize(330, 280);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        double a = Double.parseDouble(t1.getText());
        double b = Double.parseDouble(t2.getText());
        double ans = 0;

        if(e.getSource() == add)
            ans = a + b;
        else if(e.getSource() == sub)
            ans = a - b;
        else if(e.getSource() == mul)
            ans = a * b;
        else if(e.getSource() == div)
            ans = a / b;

        res.setText("Result = " + ans);
    }

    public static void main(String[] args) {
        new CalculatorGUI();
    }
}
