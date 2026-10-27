import java.util.Scanner;

// lcm of two numbers
class LcmDemo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("enter two numbers : ");
        int a = sc.nextInt();
        int b = sc.nextInt();

        int max = (a > b) ? a : b;
        while (true) {
            if (max % a == 0 && max % b == 0) {
                System.out.println("lcm = " + max);
                break;
            }
            max++;
        }
    }
}
