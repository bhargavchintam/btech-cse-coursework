// binary search on sorted array
import java.util.Scanner;

public class BinarySearch {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter n: ");
        int n = in.nextInt();
        int a[] = new int[n];
        System.out.println("Enter elements in sorted order:");
        for(int i = 0; i < n; i++)
            a[i] = in.nextInt();
        System.out.print("Enter key: ");
        int key = in.nextInt();

        int low = 0, high = n - 1, mid;
        int flag = 0;
        while(low <= high) {
            mid = (low + high) / 2;
            //System.out.println("low=" + low + " high=" + high);
            if(a[mid] == key) {
                System.out.println("Key found at position " + (mid + 1));
                flag = 1;
                break;
            } else if(a[mid] < key)
                low = mid + 1;
            else
                high = mid - 1;
        }
        if(flag == 0)
            System.out.println("Key not found");
    }
}
