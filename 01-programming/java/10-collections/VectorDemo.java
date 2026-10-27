import java.util.Vector;

// vector is legacy class but still in syllabus
public class VectorDemo {
    public static void main(String args[]) {
        Vector<Integer> v = new Vector<>();

        System.out.println("Initial capacity = " + v.capacity());

        v.add(10);
        v.add(20);
        v.add(30);
        v.addElement(40);

        System.out.println("Vector : " + v);
        System.out.println("Size = " + v.size());
        System.out.println("First : " + v.firstElement());
        System.out.println("Last : " + v.lastElement());

        v.remove(1);
        System.out.println("After remove : " + v);

        for (int i = 0; i < v.size(); i++) {
            System.out.println("element at " + i + " = " + v.elementAt(i));
        }
    }
}
