public class FinallyReturnDemo {
    static int test() {
        try {
            return 1;
        } finally {
            // finally runs even after return
            System.out.println("finally still runs");
        }
    }

    public static void main(String[] args) {
        int x = test();
        System.out.println("returned : " + x);
    }
}
