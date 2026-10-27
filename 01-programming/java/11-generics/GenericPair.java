class Pair<K, V> {
    K key;
    V value;

    Pair(K key, V value) {
        this.key = key;
        this.value = value;
    }

    K getKey() {
        return key;
    }

    V getValue() {
        return value;
    }
}

public class GenericPair {
    public static void main(String[] args) {
        Pair<Integer, String> p1 = new Pair<>(101, "Ravi");
        System.out.println(p1.getKey() + " : " + p1.getValue());

        Pair<String, Double> p2 = new Pair<>("pi", 3.14159);
        System.out.println(p2.getKey() + " : " + p2.getValue());

        Pair<String, Boolean> p3 = new Pair<>("java is easy", true);
        System.out.println(p3.getKey() + " : " + p3.getValue());
    }
}
