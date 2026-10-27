// same as SynchronizedDemo but with synchronized block
class Counter2 {
    int count = 0;

    void increment() {
        synchronized (this) {
            count++;
        }
    }
}

class Worker extends Thread {
    Counter2 c;

    Worker(Counter2 c) {
        this.c = c;
    }

    public void run() {
        for (int i = 0; i < 10000; i++) {
            c.increment();
        }
    }
}

public class SyncBlockDemo {
    public static void main(String[] args) {
        Counter2 c = new Counter2();
        Worker t1 = new Worker(c);
        Worker t2 = new Worker(c);

        t1.start();
        t2.start();
        try {
            t1.join();
            t2.join();
        } catch (InterruptedException e) {}

        System.out.printf("count = %d\n", c.count);
    }
}
