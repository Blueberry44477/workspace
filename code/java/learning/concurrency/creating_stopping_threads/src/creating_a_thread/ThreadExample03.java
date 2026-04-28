package creating_a_thread;
public class ThreadExample03 {
    public static void main(String[] args) {
        Runnable runnable = new Runnable() {
            @Override
            public void run() {
                System.out.println("Hello from runnable thread.");
            }
        };

        Thread thread = new Thread(runnable);
        thread.start();
    }
}
