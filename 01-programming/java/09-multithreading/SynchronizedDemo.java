class Counter {
    int count = 0;

    synchronized void increment() {  // without synchronized count comes less than 20000
        count++;
    }
}

class Adder extends Thread {
    Counter c;

    Adder(Counter c) {
        this.c = c;
    }

    public void run() {
        for (int i = 0; i < 10000; i++) {
            c.increment();
        }
    }
}

public class SynchronizedDemo {
    public static void main(String[] args) {
        Counter c = new Counter();
        Adder t1 = new Adder(c);
        Adder t2 = new Adder(c);

        t1.start();
        t2.start();
        try {
            t1.join();
            t2.join();
        } catch (InterruptedException e) {}

        System.out.println("final count = " + c.count);
    }
}
