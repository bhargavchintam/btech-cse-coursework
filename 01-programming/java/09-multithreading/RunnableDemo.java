class MyRunnable implements Runnable {
    public void run() {  // this runs in a separate thread
        for (int i = 1; i <= 5; i++) {
            System.out.println("runnable thread: " + i);
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {}
        }
    }
}

public class RunnableDemo {
    public static void main(String[] args) {
        MyRunnable r = new MyRunnable();
        Thread t = new Thread(r);
        t.start();
        System.out.println("main thread done");
    }
}
