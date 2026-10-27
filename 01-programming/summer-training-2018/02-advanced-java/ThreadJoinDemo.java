class Printer extends Thread {
    public void run() {
        for (int i = 1; i <= 3; i++) {
            System.out.println(getName() + " count " + i);
            try {
                Thread.sleep(200);
            } catch (InterruptedException e) {}
        }
    }
}

public class ThreadJoinDemo {
    public static void main(String args[]) {
        Printer w1 = new Printer();
        Printer w2 = new Printer();
        w1.start();
        try {
            w1.join();   // wait till w1 finishes before starting w2
        } catch (InterruptedException e) {}
        w2.start();
        try {
            w2.join();
        } catch (InterruptedException e) {}

        System.out.println("both threads over");
    }
}
