import java.util.Scanner;

// decimal to binary
class DecimalToBinary {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        System.out.print("enter a number : ");
        int n = in.nextInt();
        int binary[] = new int[32];
        int i = 0;

        while (n > 0) {
            binary[i] = n % 2;
            n = n / 2;
            i++;
        }

        System.out.print("binary = ");
        for (int j = i - 1; j >= 0; j--) {
            System.out.print(binary[j]);
        }
        System.out.println();
    }
}
