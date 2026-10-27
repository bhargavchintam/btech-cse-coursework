/* Lab Program 11
   Write a Java program with three threads. The first prints squares, the
   second prints cubes and the third prints random numbers, each with a
   one second delay between values.
   javac Lab11_ThreadDemo.java && java Lab11_ThreadDemo */

import java.util.Random;

class SquareThread extends Thread {
    public void run() {
        for(int i = 1; i <= 5; i++) {
            System.out.println("square of " + i + " = " + (i * i));
            try { Thread.sleep(1000); } catch(InterruptedException e) {}
        }
    }
}

class CubeThread extends Thread {
    public void run() {
        for(int i = 1; i <= 5; i++) {
            System.out.println("cube of " + i + " = " + (i * i * i));
            try { Thread.sleep(1000); } catch(InterruptedException e) {}
        }
    }
}

class RandomThread extends Thread {
    public void run() {
        Random r = new Random();
        for(int i = 1; i <= 5; i++) {
            System.out.println("random number = " + r.nextInt(100));
            try { Thread.sleep(1000); } catch(InterruptedException e) {}
        }
    }
}

class Lab11_ThreadDemo {
    public static void main(String[] args) {
        new SquareThread().start();
        new CubeThread().start();
        new RandomThread().start();
    }
}
