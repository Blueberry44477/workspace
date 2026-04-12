import java.util.ArrayList;

public class Application {
    public static void main(String[] args) {
        // 1.
        ConsoleReader reader = new ConsoleReader();
        String url = reader.readValidURL();
        System.out.println("Valid URL: " + url);

        reader.close();

        // 2. ArrayList.
        ArrayList<String> urlList = new ArrayList<>();

        urlList.add("https://example.com");
        urlList.add("htp://invalid.com");
        urlList.add("http://valid.org");
        urlList.add("invalid-url");

        System.out.println("Before:");
        System.out.println(urlList);

        // Фільтруємо недійсні URL
        URLManager.filterInvalidURLs(urlList);

        System.out.println("After:");
        System.out.println(urlList);
    }
}
