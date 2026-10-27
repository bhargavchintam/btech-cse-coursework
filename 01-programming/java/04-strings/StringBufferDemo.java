// stringbuffer methods
public class StringBufferDemo {
    public static void main(String args[]) {
        StringBuffer sb = new StringBuffer("Hello");

        sb.append(" World");
        System.out.println("After append: " + sb);

        sb.insert(5, " Java");
        System.out.println("After insert: " + sb);

        sb.reverse();
        System.out.println("After reverse: " + sb);

        sb.reverse();
        sb.delete(5, 10);
        System.out.println("After delete: " + sb);

        System.out.println("Length: " + sb.length());
        System.out.println("Capacity: " + sb.capacity());
    }
}
