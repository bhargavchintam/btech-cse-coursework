import javax.swing.*;

public class CheckboxRadioDemo {
    public static void main(String[] args) {
        JFrame f = new JFrame("Checkbox and Radio");
        f.setLayout(null);

        JLabel l1 = new JLabel("Languages known:");
        l1.setBounds(50, 30, 150, 30);
        JCheckBox c1 = new JCheckBox("C");
        JCheckBox c2 = new JCheckBox("Java");
        c1.setBounds(50, 60, 100, 30);
        c2.setBounds(50, 90, 100, 30);

        JLabel l2 = new JLabel("Gender:");
        l2.setBounds(50, 140, 150, 30);
        JRadioButton r1 = new JRadioButton("Male");
        JRadioButton r2 = new JRadioButton("Female");
        r1.setBounds(50, 170, 100, 30);
        r2.setBounds(50, 200, 100, 30);

        ButtonGroup bg = new ButtonGroup();
        bg.add(r1);   // group makes sure only one radio gets selected
        bg.add(r2);

        f.add(l1);
        f.add(c1);
        f.add(c2);
        f.add(l2);
        f.add(r1);
        f.add(r2);
        f.setSize(300, 320);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setVisible(true);
    }
}
