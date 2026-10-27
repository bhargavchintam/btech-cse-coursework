public class TypeCasting {
    public static void main(String[] args) {
        int a = 10;
        double d = a;
        System.out.println("int to double : " + d);

        double x = 9.78;
        int y = (int) x; // explicit cast, decimal part is lost
        System.out.println("double to int : " + y);

        char ch = 'B';
        int n = ch;
        System.out.println("char to int : " + n);

        int m = 97;
        char c = (char) m;
        System.out.println("int to char : " + c);
    }
}
