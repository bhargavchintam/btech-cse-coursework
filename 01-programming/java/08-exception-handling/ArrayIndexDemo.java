import java.util.Scanner;

public class ArrayIndexDemo {
    public static void main(String[] args) {
        int arr[] = {10, 20, 30, 40, 50};
        Scanner s = new Scanner(System.in);

        System.out.print("enter index : ");
        int i = s.nextInt();
        try {
            System.out.println("element = " + arr[i]);
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("invalid index, array size is 5");
        }
    }
}
