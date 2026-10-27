class StringDemo {
    public static void main(String args[]) {
        String s1 = "hello";
        String s2 = "hello";
        String s3 = new String("hello");

        System.out.println(s1 == s2);
        System.out.println(s1 == s3); // == compares references not content
        System.out.println(s1.equals(s3));

        String s4 = s1 + " world";
        System.out.println(s4);
        System.out.println("length is " + s4.length());
    }
}
