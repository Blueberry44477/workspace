import java.net.MalformedURLException;
import java.util.Scanner;

public class ConsoleReader {
    private Scanner scanner;

    public ConsoleReader() {
        this.scanner = new Scanner(System.in);
    }

    public String readValidURL() {
        while(true) {
            try {
                System.out.print("Enter URL: ");
                String input = scanner.nextLine();
    
                URLManager.validate(input);
                return input;
            } catch (MalformedURLException exception) {
                System.out.println("Invalid URL: " + exception.getMessage());
            }
        }
    }

    // Or just put scanner in try-with-resources.
    public void close() {
        scanner.close();
    }
}
