// sum of digits using while loop
class WhileDemo {
    public static void main(String args[]) {
        int n = 4568;
        int sum = 0;

        while (n > 0) {
            sum = sum + n % 10;
            n = n / 10;
        }
        System.out.println("sum of digits = " + sum);
    }
}
