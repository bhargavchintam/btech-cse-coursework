// static variable is shared by all objects
class Counter {
    static int count = 0;

    Counter() {
        count++;
    }
}

class StaticDemo {
    public static void main(String args[]) {
        Counter c1 = new Counter();
        Counter c2 = new Counter();
        Counter c3 = new Counter();
        System.out.println("objects created = " + Counter.count);
    }
}
