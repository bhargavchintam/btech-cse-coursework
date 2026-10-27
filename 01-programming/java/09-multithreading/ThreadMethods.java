public class ThreadMethods {
    public static void main(String[] args) {
        Thread t = Thread.currentThread();
        System.out.println("Current thread: " + t.getName());

        t.setName("MainThread");
        System.out.println("After name change: " + t.getName());
        System.out.println("Priority: " + t.getPriority());

        try {
            for (int i = 5; i > 0; i--) {
                System.out.println(i);
                Thread.sleep(300);
            }
        } catch (InterruptedException e) {
            System.out.println("main thread interrupted");
        }
    }
}
