// passing object to method and returning object

class Complex {
    int real, imag;

    Complex(int r, int i) {
        real = r;
        imag = i;
    }

    Complex add(Complex c) {
        Complex temp = new Complex(real + c.real, imag + c.imag);
        return temp;
    }

    void display() {
        System.out.println(real + " + " + imag + "i");
    }
}

public class PassObjectToMethod {
    public static void main(String[] args) {
        Complex c1 = new Complex(3, 4);
        Complex c2 = new Complex(5, 2);

        Complex c3 = c1.add(c2);

        c1.display();
        c2.display();
        System.out.println("sum is");
        c3.display();
    }
}
