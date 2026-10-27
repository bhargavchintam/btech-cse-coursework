public class MultipleCatch {
    public static void main(String args[]) {
        int a[] = {5, 10, 15};

        try {
            int i = a[1] / 0;
            System.out.println(a[5]);
        } catch (ArithmeticException e) {
            System.out.println("arithmetic exception: " + e.getMessage());
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("array index out of bounds");
        } catch (Exception e) {  // parent exception must come last
            System.out.println("some other exception");
        }
        System.out.println("rest of the code");
    }
}
