public class GenericStack {
    public static void main(String[] args) {
        MyStack<Integer> st = new MyStack<>(5);
        st.push(10);
        st.push(20);
        st.push(30);

        System.out.println("Popped : " + st.pop());
        System.out.println("Popped : " + st.pop());

        MyStack<String> st2 = new MyStack<>(3);
        st2.push("abc");
        st2.push("xyz");
        System.out.println("Popped : " + st2.pop());
        System.out.println("Popped : " + st2.pop());
    }
}

class MyStack<T> {
    T[] arr;
    int top;

    @SuppressWarnings("unchecked")
    MyStack(int size) {
        // cant do new T[size] directly, found this cast on stackoverflow
        arr = (T[]) new Object[size];
        top = -1;
    }

    void push(T x) {
        if (top == arr.length - 1) {
            System.out.println("stack is full");
            return;
        }
        arr[++top] = x;
    }

    T pop() {
        if (top == -1) {
            System.out.println("stack is empty");
            return null;
        }
        return arr[top--];
    }
}
