public class GenericMethod {
    static <T> void printArray(T[] arr) {
        for (T x : arr) {
            System.out.print(x + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Integer[] a = {10, 20, 30, 40, 50};
        String[] s = {"java", "python", "c", "cpp"};

        System.out.println("Integer array :");
        printArray(a);

        System.out.println("String array :");
        printArray(s);
    }
}
