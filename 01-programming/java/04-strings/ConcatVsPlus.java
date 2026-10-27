// concat method and + operator
public class ConcatVsPlus {
    public static void main(String[] args) {
        String s1 = "Hello";
        String s2 = "World";

        String s3 = s1.concat(s2);
        String s4 = s1 + " " + s2;

        System.out.println("Using concat: " + s3);
        System.out.println("Using + : " + s4);

        String s5 = s1 + 10;
        System.out.println(s5);
    }
}
