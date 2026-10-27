import java.util.LinkedList;

public class LinkedListDemo {
    public static void main(String[] args) {
        LinkedList<Integer> ll = new LinkedList<>();

        ll.add(10);
        ll.add(20);
        ll.add(30);
        System.out.println("List : " + ll);

        ll.addFirst(5);
        ll.addLast(40);
        System.out.println("After addFirst and addLast : " + ll);

        System.out.println("First element : " + ll.getFirst());
        System.out.println("Last element : " + ll.getLast());

        ll.removeFirst();
        ll.removeLast();
        System.out.println("After removing first and last : " + ll);
    }
}
