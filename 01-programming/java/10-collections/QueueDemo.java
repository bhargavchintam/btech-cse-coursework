import java.util.LinkedList;
import java.util.Queue;

// using linkedlist as a queue
public class QueueDemo {
    public static void main(String[] args) {
        Queue<String> q = new LinkedList<>();

        q.offer("ravi");
        q.offer("amit");
        q.offer("kiran");
        q.offer("suma");

        System.out.println("Queue : " + q);
        System.out.println("Front element : " + q.peek());

        System.out.println("Removed : " + q.poll());
        System.out.println("Removed : " + q.poll());

        System.out.println("Queue now : " + q);
        System.out.println("Front now : " + q.peek());
    }
}
