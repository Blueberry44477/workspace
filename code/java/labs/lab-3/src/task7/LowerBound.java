package src.task7;
import java.util.List;

public class LowerBound {
    public static void addToList(List<? super Integer> list) {
        for (int i = 1; i <= 10; i++) {
            list.add(i);
        }
    }
}
