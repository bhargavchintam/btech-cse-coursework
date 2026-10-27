public class VarargsDemo {
    static int add(int... nums) {
        int sum = 0;
        for (int n : nums) {
            sum = sum + n;
        }
        return sum;
    }

    public static void main(String args[]) {
        System.out.println("add() = " + add());
        System.out.println("add(5) = " + add(5));
        System.out.println("add(2,4,6) = " + add(2, 4, 6));
        System.out.println("add(1,2,3,4,5) = " + add(1, 2, 3, 4, 5));
    }
}
