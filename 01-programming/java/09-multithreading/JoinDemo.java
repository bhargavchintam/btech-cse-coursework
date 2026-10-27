class JThread extends Thread {
    public void run() {
        for (int i = 1; i <= 5; i++) {
            System.out.println(getName() + " : " + i);
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {}
        }
    }
}

public class JoinDemo {
    public static void main(String[] args) {
        JThread t1 = new JThread();
        JThread t2 = new JThread();
        t1.setName("t1");
        t2.setName("t2");

        t1.start();
        try {
            t1.join();  // without join the output of t1 and t2 gets mixed
        } catch (InterruptedException e) {}
        t2.start();
    }
}
