class Car {
    String model;
    int speed;

    void start() {
        System.out.println(model + " started");
    }

    void accelerate() {
        speed = speed + 20;
        System.out.println("speed is now " + speed);
    }
}

class CarClass {
    public static void main(String[] args) {
        Car c = new Car();
        c.model = "Maruti Swift";
        c.speed = 0;
        c.start();
        c.accelerate();
        c.accelerate();
    }
}
