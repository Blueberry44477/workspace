package creating_a_thread;
public class ThreadExample04 {
    public static void main(String[] args) {
        Runnable runnable = () -> {
            String threadName = Thread.currentThread().getName();
            System.out.println("Hello from " + threadName);
        };
        Thread thread = new Thread(runnable, "My Thread");
        thread.start();
    }
}
