class Background extends Thread {
    public void run() {
        while (true) {
            System.out.println("daemon working...");
            try {
                Thread.sleep(300);
            } catch (InterruptedException e) {}
        }
    }
}

public class DaemonThreadDemo {
    public static void main(String args[]) {
        Background b = new Background();
        b.setDaemon(true);   // daemon stops when main ends
        b.start();

        for (int i = 1; i <= 3; i++) {
            System.out.println("main " + i);
            try {
                Thread.sleep(300);
            } catch (InterruptedException e) {}
        }
        System.out.println("main done, daemon will stop");
    }
}
