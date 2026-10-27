// wrapper classes and parsing
class WrapperDemo {
    public static void main(String[] args) {
        int a = 50;
        Integer obj = a; // autoboxing
        int b = obj;

        System.out.println("obj = " + obj);
        System.out.println("b = " + b);

        String s1 = "123";
        String s2 = "45.67";
        int x = Integer.parseInt(s1);
        double d = Double.parseDouble(s2);

        System.out.println("x + 1 = " + (x + 1));
        System.out.println("d + 1 = " + (d + 1));
        System.out.println("max int = " + Integer.MAX_VALUE);
    }
}
