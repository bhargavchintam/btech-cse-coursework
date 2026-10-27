import java.util.Scanner;

// second largest element in array
class SecondLargest {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("enter size : ");
        int n = in.nextInt();
        int arr[] = new int[n];

        System.out.println("enter elements :");
        for (int i = 0; i < n; i++) {
            arr[i] = in.nextInt();
        }

        int first = Integer.MIN_VALUE, second = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            if (arr[i] > first) {
                second = first;
                first = arr[i];
            } else if (arr[i] > second && arr[i] != first) {
                second = arr[i];
            }
        }
        System.out.println("second largest = " + second);
    }
}
