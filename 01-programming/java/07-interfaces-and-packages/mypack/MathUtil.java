package mypack;

public class MathUtil {
    public static int max(int a, int b) {
        if (a > b)
            return a;
        else
            return b;
    }

    public static int factorial(int n) {
        int fact = 1;
        for (int i = 1; i <= n; i++)
            fact = fact * i;
        return fact;
    }
}
