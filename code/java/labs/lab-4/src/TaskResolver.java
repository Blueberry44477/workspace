import java.util.Optional;
import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;

public class TaskResolver {
    public static Optional<String> firstTask(List<String> list) {

        return list.stream()
            .filter(str -> str.startsWith("X"))
            .filter(str -> str.length() > 5)
            .findFirst()
            .or(() -> Optional.of("Default"));
    }

    // Звести список до списку цілих чисел.
    public static List<Integer> secondTask(List<Optional<Integer>> list) {

        // return list.stream()
        //     .filter(Optional::isPresent)
        //     .map(Optional::get)
        //     .collect(Collectors.toList());
        
        return list.stream()
            .flatMap(Optional::stream)
            .collect(Collectors.toList());
    }

    // Find Longest String.
    public static Optional<String> thirdTask(List<String> names) {
        return names.stream().max(Comparator.comparingInt(String::length));
    }


}
