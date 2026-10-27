class Counter {
    int count = 0;

    // without synchronized count comes less than 20000
    synchronized void increment() {
        count++;
    }
}

class Worker extends Thread {
    Counter c;

    Worker(Counter c) {
        this.c = c;
    }

    public void run() {
        for (int i = 0; i < 10000; i++) {
            c.increment();
        }
    }
}

public class SyncCounter {
    public static void main(String[] args) throws InterruptedException {
        Counter c = new Counter();
        Worker t1 = new Worker(c);
        Worker t2 = new Worker(c);

        t1.start();
        t2.start();
        t1.join();
        t2.join();

        System.out.println("Count = " + c.count);
    }
}
