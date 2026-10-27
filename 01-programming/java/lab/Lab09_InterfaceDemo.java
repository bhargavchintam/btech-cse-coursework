/* Lab Program 9
   Define an interface Vehicle with methods start() and stop(). Implement
   it in classes Car and Bike and demonstrate interface reference.
   javac Lab09_InterfaceDemo.java && java Lab09_InterfaceDemo */

interface Vehicle {
    void start();
    void stop();
}

class Car implements Vehicle {
    public void start() {
        System.out.println("Car starts with a key");
    }
    public void stop() {
        System.out.println("Car stops with disc brakes");
    }
}

class Bike implements Vehicle {
    public void start() {
        System.out.println("Bike starts with a kick");
    }
    public void stop() {
        System.out.println("Bike stops with drum brakes");
    }
}

class Lab09_InterfaceDemo {
    public static void main(String[] args) {
        Vehicle v;
        v = new Car();
        v.start();
        v.stop();
        v = new Bike();
        v.start();
        v.stop();
    }
}
