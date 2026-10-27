class DThread extends Thread {
    public void run() {
        if (isDaemon()) {
            System.out.println(getName() + " is a daemon thread");
        } else {
            System.out.println(getName() + " is a user thread");
        }
    }
}

public class DaemonThreadDemo {
    public static void main(String args[]) {
        DThread t1 = new DThread();
        DThread t2 = new DThread();
        t1.setName("t1");
        t2.setName("t2");

        t1.setDaemon(true);  // daemon thread ends when main thread ends
        t1.start();
        t2.start();
    }
}
