public class MultiCatchDemo {
    public static void main(String[] args) {
        String[] data = {"10", "abc", "5"};

        for (int i = 0; i <= data.length; i++) {
            try {
                int n = Integer.parseInt(data[i]);
                System.out.println("100 / " + n + " = " + (100 / n));
            } catch (NumberFormatException | ArrayIndexOutOfBoundsException e) {
                System.out.println("bad input : " + e);
            }
        }
    }
}
