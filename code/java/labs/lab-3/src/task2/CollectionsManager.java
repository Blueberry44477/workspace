package src.task2;
import java.util.Set;
import java.util.HashSet;
import java.util.Map;
import java.util.HashMap;
import java.util.List;

public class CollectionsManager {
    public <T> Set<T> getUnique(List<T> list) {
        return new HashSet<>(list);
    }

    public <T> Map<T, Integer> count(List<T> list) {
        Map<T, Integer> occurrences = new HashMap<>();
        for (T obj : list)
            occurrences.put(obj, occurrences.getOrDefault(obj, 0) + 1);
        return occurrences;
    }
}
