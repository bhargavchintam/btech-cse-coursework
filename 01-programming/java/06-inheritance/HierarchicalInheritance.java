// hierarchical inheritance - one parent two children

class Vehicle {
    void start() {
        System.out.println("vehicle started");
    }
}

class Car extends Vehicle {
    void wheels() {
        System.out.println("car has 4 wheels");
    }
}

class Bike extends Vehicle {
    void wheels() {
        System.out.println("bike has 2 wheels");
    }
}

public class HierarchicalInheritance {
    public static void main(String[] args) {
        Car c = new Car();
        c.start();
        c.wheels();

        Bike b = new Bike();
        b.start();
        b.wheels();
    }
}
