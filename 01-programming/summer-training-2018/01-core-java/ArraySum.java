class ArraySum {
    public static void main(String[] args) {
        int arr[] = {12, 45, 7, 89, 23};
        int sum = 0;

        for (int i = 0; i < arr.length; i++) {
            sum = sum + arr[i];
        }
        System.out.println("Sum = " + sum);
        System.out.println("Average = " + (double) sum / arr.length);
    }
}
