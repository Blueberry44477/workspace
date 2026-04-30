package thread_actions;
public class ThreadSleep {
    public static void main(String[] args) {
        Runnable runnable = () -> {
            System.out.println("Started");
            try {
                Thread.sleep(2000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            System.out.println("Finished");
        };
        Thread thread = new Thread(runnable);
        thread.start();
    }
}