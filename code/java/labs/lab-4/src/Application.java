import java.util.Arrays;
import java.util.List;

public class Application {
    public static void main(String[] args) {
        List<String> list = Arrays.asList("Xanax", "Apple", "Xyzkyg");
        System.out.println(TaskResolver.firstTask(list));
    }
}
