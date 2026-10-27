// thread priority demo
class PThread extends Thread {
    public void run() {
        System.out.println(getName() + " has priority " + getPriority());
    }
}

public class ThreadPriority {
    public static void main(String args[]) {
        PThread t1 = new PThread();
        PThread t2 = new PThread();
        PThread t3 = new PThread();

        t1.setName("low");
        t2.setName("normal");
        t3.setName("high");
        t1.setPriority(Thread.MIN_PRIORITY);
        t2.setPriority(Thread.NORM_PRIORITY);
        t3.setPriority(Thread.MAX_PRIORITY);

        t1.start();
        t2.start();
        t3.start();
    }
}
