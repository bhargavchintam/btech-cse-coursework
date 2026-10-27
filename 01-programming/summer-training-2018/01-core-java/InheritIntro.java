/* Bindu Bhargava  21-07-18 */
class Animal {
    void eat() {
        System.out.println("animal is eating");
    }

    void sleep() {
        System.out.println("animal is sleeping");
    }
}

class Dog extends Animal {
    void bark() {
        System.out.println("dog is barking");
    }
}

class InheritIntro {
    public static void main(String[] args) {
        Dog d = new Dog();
        d.eat();
        d.sleep();
        d.bark();
    }
}
