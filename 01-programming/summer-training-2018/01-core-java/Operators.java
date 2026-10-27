class Operators {
    public static void main(String[] args) {
        int a = 10, b = 3;

        System.out.println("a+b = " + (a + b));
        System.out.println("a-b = " + (a - b));
        System.out.println("a*b = " + (a * b));
        System.out.println("a/b = " + (a / b));
        System.out.println("a%b = " + (a % b));

        int c = a++;
        System.out.println("c = " + c);
        System.out.println("a = " + a);
        c = ++a;
        System.out.println("c = " + c);

        System.out.println(a > b);
        System.out.println(a == b);
    }
}
