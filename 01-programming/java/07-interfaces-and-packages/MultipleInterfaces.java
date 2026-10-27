interface Printable {
    void print();
}

interface Showable {
    void show();
}

// java's answer to multiple inheritance
class Demo implements Printable, Showable {
    public void print() {
        System.out.println("printing document");
    }

    public void show() {
        System.out.println("showing document");
    }
}

public class MultipleInterfaces {
    public static void main(String[] args) {
        Demo d = new Demo();
        d.print();
        d.show();
    }
}
