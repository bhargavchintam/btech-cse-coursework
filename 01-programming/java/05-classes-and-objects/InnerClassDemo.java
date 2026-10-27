// member inner class example

public class InnerClassDemo {
    int x = 10;

    class Inner {
        void show() {
            System.out.println("inside inner class");
            System.out.println("x = " + x);
        }
    }

    public static void main(String[] args) {
        InnerClassDemo obj = new InnerClassDemo();
        InnerClassDemo.Inner in = obj.new Inner();
        in.show();
    }
}
