import java.util.AbstractMap.SimpleEntry;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;

public class WordCount {

    static class Mapper {
        List<SimpleEntry<String, Integer>> map(String line) {
            List<SimpleEntry<String, Integer>> out = new ArrayList<>();
            for (String w : line.split("\\s+")) {
                if (!w.isEmpty()) out.add(new SimpleEntry<>(w, 1));
            }
            return out;
        }
    }

    static class Reducer {
        int reduce(List<Integer> counts) {
            int total = 0;
            for (int c : counts) total += c;
            return total;
        }
    }

    public static void main(String[] args) {
        String[] text = {
            "the sun is hot the sea is deep",
            "the sun sets and the sea is calm",
        };

        Mapper mapper = new Mapper();
        Reducer reducer = new Reducer();

        TreeMap<String, List<Integer>> groups = new TreeMap<>();
        for (String line : text) {
            for (SimpleEntry<String, Integer> kv : mapper.map(line)) {
                groups.computeIfAbsent(kv.getKey(), k -> new ArrayList<>()).add(kv.getValue());
            }
        }

        for (Map.Entry<String, List<Integer>> e : groups.entrySet()) {
            System.out.println(e.getKey() + "\t" + reducer.reduce(e.getValue()));
        }
    }
}
