class First extends Thread {
    public void run() {
        for (int i = 1; i <= 5; i++) {
            System.out.println("First: " + i);
            try {
                Thread.sleep(150);
            } catch (InterruptedException e) {}
        }
    }
}

class Second extends Thread {
    public void run() {
        for (int i = 1; i <= 5; i++) {
            System.out.println("Second: " + i);
            try {
                Thread.sleep(150);
            } catch (InterruptedException e) {}
        }
    }
}

public class MultipleThreads {
    public static void main(String[] args) {
        First t1 = new First();
        Second t2 = new Second();
        t1.start();
        t2.start();
    }
}
