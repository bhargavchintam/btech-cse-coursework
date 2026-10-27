// stringbuilder is faster than stringbuffer because it is not synchronized
public class StringBuilderDemo {
    public static void main(String[] args) {
        StringBuilder sb = new StringBuilder("Java");

        sb.append(" Programming");
        System.out.println(sb);

        sb.insert(4, " Language");
        System.out.println(sb);

        sb.reverse();
        System.out.println(sb);

        sb.reverse();
        sb.delete(0, 5);
        System.out.println(sb);
    }
}
