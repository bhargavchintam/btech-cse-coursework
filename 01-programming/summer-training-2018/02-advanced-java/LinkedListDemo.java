import java.util.LinkedList;

public class LinkedListDemo {
    public static void main(String[] args) {
        LinkedList<String> ll = new LinkedList<>();
        ll.add("mon");
        ll.add("tue");
        ll.add("wed");
        ll.addFirst("sun");
        ll.addLast("thu");

        System.out.println(ll);
        System.out.println("first : " + ll.getFirst());
        System.out.println("last : " + ll.getLast());

        ll.removeFirst();
        ll.removeLast();
        System.out.println("after removing ends : " + ll);
        System.out.println("size : " + ll.size());
    }
}
