import java.util.Scanner;

// power of a number without Math.pow
class PowerDemo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("enter base and exponent : ");
        int base = sc.nextInt();
        int exp = sc.nextInt();
        long result = 1;

        for (int i = 1; i <= exp; i++) {
            result = result * base;
        }
        System.out.println(base + " ^ " + exp + " = " + result);
    }
}
