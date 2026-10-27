import java.util.Stack;

public class StackDemo {
    public static void main(String[] args) {
        Stack<Integer> st = new Stack<>();

        st.push(10);
        st.push(20);
        st.push(30);
        st.push(40);

        System.out.println("Stack : " + st);
        System.out.println("Top element : " + st.peek());

        System.out.println("Popped : " + st.pop());
        System.out.println("Popped : " + st.pop());

        System.out.println("Stack now : " + st);
        System.out.println("Top element now : " + st.peek());
        System.out.println("Is stack empty ? " + st.empty());
    }
}
