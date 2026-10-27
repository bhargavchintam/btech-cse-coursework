import java.util.Arrays;

public class StreamNumbers {
    public static void main(String[] args) {
        int[] nums = {12, 45, 7, 89, 23, 56, 34};

        int sum = Arrays.stream(nums).sum();
        System.out.println("Sum = " + sum);

        double avg = Arrays.stream(nums).average().getAsDouble();
        System.out.printf("Average = %.2f\n", avg);

        int max = Arrays.stream(nums).max().getAsInt();
        System.out.println("Max = " + max);

        int min = Arrays.stream(nums).min().getAsInt();
        System.out.println("Min = " + min);
    }
}
