// static variable to count number of objects

class Counter {
    static int count = 0;

    Counter() {
        count++;
    }
}

public class StaticKeyword {
    public static void main(String[] args) {
        Counter c1 = new Counter();
        Counter c2 = new Counter();
        Counter c3 = new Counter();

        System.out.println("Number of objects created = " + Counter.count);
    }
}
