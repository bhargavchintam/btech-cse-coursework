class Buffer {
    int data;
    boolean empty = true;

    synchronized void produce(int val) {
        while (!empty) {
            try {
                wait();
            } catch (InterruptedException e) {}
        }
        data = val;
        empty = false;
        //System.out.println("empty = " + empty);
        System.out.println("Produced: " + val);
        notify();
    }

    synchronized void consume() {
        while (empty) {
            try {
                wait();
            } catch (InterruptedException e) {}
        }
        System.out.println("Consumed: " + data);
        empty = true;
        notify();
    }
}

class Producer extends Thread {
    Buffer b;

    Producer(Buffer b) {
        this.b = b;
    }

    public void run() {
        for (int i = 1; i <= 5; i++) {
            b.produce(i);
        }
    }
}

class Consumer extends Thread {
    Buffer b;

    Consumer(Buffer b) {
        this.b = b;
    }

    public void run() {
        for (int i = 1; i <= 5; i++) {
            b.consume();
        }
    }
}

public class ProducerConsumer {
    public static void main(String[] args) {
        Buffer b = new Buffer();
        Producer p = new Producer(b);
        Consumer c = new Consumer(b);
        p.start();
        c.start();
    }
}
