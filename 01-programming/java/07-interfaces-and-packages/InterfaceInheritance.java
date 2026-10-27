interface Animal {
    void eat();
}

interface Pet extends Animal {
    void play();
}

class Dog implements Pet {
    public void eat() {
        System.out.println("dog eats bones");
    }

    public void play() {
        System.out.println("dog plays fetch");
    }
}

public class InterfaceInheritance {
    public static void main(String args[]) {
        Dog d = new Dog();
        d.eat();
        d.play();
    }
}
