// nested try blocks
public class NestedTry {
    public static void main(String[] args) {
        try {
            try {
                int a = 10 / 0;
                System.out.println(a);
            } catch (ArithmeticException e) {
                System.out.println("inner catch: " + e.getMessage());
            }

            int arr[] = new int[3];
            arr[5] = 100;
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("outer catch: " + e);
        }
        System.out.println("done");
    }
}
