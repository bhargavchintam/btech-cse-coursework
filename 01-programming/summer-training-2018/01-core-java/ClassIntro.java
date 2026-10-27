// my first class
class Dog {
    String name;
    String breed;
    int age;

    void bark() {
        System.out.println(name + " says woof woof");
    }
}

class ClassIntro {
    public static void main(String[] args) {
        Dog d1 = new Dog();
        d1.name = "Tommy";
        d1.breed = "Labrador";
        d1.age = 3;
        d1.bark();
        System.out.println(d1.name + " is a " + d1.breed + ", age " + d1.age);

        Dog d2 = new Dog();
        d2.name = "Sheru";
        d2.bark();
    }
}
