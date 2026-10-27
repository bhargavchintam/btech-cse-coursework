// call by value demo

class Data {
    int val;

    Data(int v) {
        val = v;
    }
}

public class CallByValueDemo {
    static void swap(int a, int b) {
        int temp = a;
        a = b;
        b = temp;
    }

    static void change(Data d) {
        d.val = 100;
    }

    public static void main(String args[]) {
        int x = 10, y = 20;
        swap(x, y);
        System.out.println("After swap x = " + x + " y = " + y);
        // swap didnt work, java always passes a copy of the value

        Data d = new Data(50);
        change(d);
        System.out.println("After change val = " + d.val);
    }
}
