package src.task5;
import java.util.Objects;

public class Pair<K, V> {
    private K first;
    private V second;

    public Pair(K first, V second) {
        this.first = first;
        this.second = second;
    }

    public K getFirst() { return first; }
    public V getSecond() { return second; }

    public boolean isEqualTo(Pair<K, V> other) {
        if (other == null) 
            return false;
        return Objects.equals(this.first, other.first) && 
               Objects.equals(this.second, other.second);
    }

    @Override
    public String toString() {
        return String.format("Pair{first=%s, second=%s}", first, second);
    }
}