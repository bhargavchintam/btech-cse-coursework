// string methods
class StringMethodsDemo {
    public static void main(String[] args) {
        String str = "Java Programming";

        System.out.println(str.toUpperCase());
        System.out.println(str.toLowerCase());
        System.out.println(str.length());
        System.out.println(str.charAt(5));
        System.out.println(str.substring(5));
        System.out.println(str.substring(0, 4));
        System.out.println(str.indexOf("gram"));
        System.out.println(str.replace('a', 'o'));
        System.out.println("  hello  ".trim());
        System.out.println(str.contains("Java"));
    }
}
