/* Lab Program 4
   Write a Java program to search for a key element in a sorted array
   using binary search.
   javac Lab04_BinarySearch.java && java Lab04_BinarySearch */

import java.util.Scanner;

class Lab04_BinarySearch {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter n: ");
        int n = in.nextInt();
        int arr[] = new int[n];
        System.out.println("Enter " + n + " elements in sorted order");
        for(int i = 0; i < n; i++)
            arr[i] = in.nextInt();
        System.out.print("Enter key: ");
        int key = in.nextInt();

        int low = 0, high = n - 1, pos = -1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(arr[mid] == key) {
                pos = mid;
                break;
            }
            else if(arr[mid] < key)
                low = mid + 1;
            else
                high = mid - 1;
        }

        if(pos == -1)
            System.out.println(key + " not found");
        else
            System.out.println(key + " found at position " + (pos + 1));
    }
}
