// creating a thread by extending Thread class
class MyThread extends Thread {
    public void run() {
        for (int i = 1; i <= 5; i++) {
            System.out.println("child thread " + i);
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {}
        }
    }
}

public class ThreadClassDemo {
    public static void main(String[] args) {
        MyThread t = new MyThread();
        t.start();

        for (int i = 1; i <= 5; i++) {
            System.out.println("main thread " + i);
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {}
        }
    }
}
