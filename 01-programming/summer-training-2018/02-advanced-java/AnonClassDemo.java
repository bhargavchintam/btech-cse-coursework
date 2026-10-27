public class AnonClassDemo {
    public static void main(String[] args) {
        Runnable r = new Runnable() {
            public void run() {
                for (int i = 1; i <= 3; i++) {
                    System.out.println("running " + i);
                }
            }
        };

        Thread t = new Thread(r);
        t.start();

        try {
            t.join();
        } catch (InterruptedException e) {}

        System.out.println("done");
    }
}
