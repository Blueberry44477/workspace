import java.net.MalformedURLException;
import java.net.URL;
import java.util.ArrayList;
import java.util.Iterator;

public class URLManager {
    // 1. Exceptions.
    public static void validate(String url) throws MalformedURLException {
        if (url == null || url.isEmpty())
            throw new MalformedURLException("URL is empty");
        
        if (!(url.startsWith("http://") || url.startsWith("https://")))
            throw new MalformedURLException("URL must start with http:// or https://");
    }

    // 2. URL Validation Method.
    public static boolean boolValidate(String url) {
        try {
            new URL(url);  // If the url is faulty -> throws ex.
            return true;
        } catch (MalformedURLException e) {
            return false;
        }
    }

    // 2. URL Filtering.
    public static void filterInvalidURLs(ArrayList<String> urls) {
        Iterator<String> iterator = urls.iterator();
        while (iterator.hasNext()) {
            String url = iterator.next();
            if (!URLManager.boolValidate(url)) {
                iterator.remove();
            }
        }
    }

}