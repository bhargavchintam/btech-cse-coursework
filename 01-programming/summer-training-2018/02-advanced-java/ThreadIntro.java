class MyThread extends Thread {
    public void run() {
        // this runs in a separate thread
        for (int i = 1; i <= 5; i++) {
            System.out.println("child thread " + i);
            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {}
        }
    }
}

public class ThreadIntro {
    public static void main(String args[]) {
        MyThread t = new MyThread();
        t.start();

        for (int i = 1; i <= 5; i++) {
            System.out.println("main thread " + i);
            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {}
        }
    }
}
