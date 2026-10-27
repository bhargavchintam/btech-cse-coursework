class MyRunnable implements Runnable {
    public void run() {
        for (int i = 1; i <= 5; i++) {
            System.out.println(Thread.currentThread().getName() + " : " + i);
            try {
                Thread.sleep(300);
            } catch (InterruptedException e) {}
        }
    }
}

public class RunnableIntro {
    public static void main(String[] args) {
        MyRunnable r = new MyRunnable();
        Thread t1 = new Thread(r);
        Thread t2 = new Thread(r);
        t1.start();
        t2.start();
    }
}
