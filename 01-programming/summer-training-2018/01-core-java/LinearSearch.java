import java.util.Scanner;

// linear search
class LinearSearch {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("enter size : ");
        int n = sc.nextInt();
        int arr[] = new int[n];

        System.out.println("enter elements :");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        System.out.print("enter element to search : ");
        int key = sc.nextInt();
        int pos = -1;

        for (int i = 0; i < n; i++) {
            if (arr[i] == key) {
                pos = i;
                break;
            }
        }

        if (pos == -1)
            System.out.println("element not found");
        else
            System.out.println("element found at index " + pos);
    }
}
