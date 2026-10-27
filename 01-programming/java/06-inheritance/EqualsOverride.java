// before overriding equals both == and equals gave false

class Point {
    int x, y;

    Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public boolean equals(Object o) {
        Point p = (Point) o;
        return this.x == p.x && this.y == p.y;
    }
}

public class EqualsOverride {
    public static void main(String[] args) {
        Point p1 = new Point(2, 3);
        Point p2 = new Point(2, 3);

        System.out.println("p1 == p2 : " + (p1 == p2));
        System.out.println("p1.equals(p2) : " + p1.equals(p2));
    }
}
