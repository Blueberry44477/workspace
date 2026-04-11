package thread_actions;

public class ThreadInterrupt {
    public static void main(String[] args) {
        Runnable runnable = () -> {
            System.out.println("Thread start");
            try {
                Thread.sleep(10000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            System.out.println("End of the thread.");
        };
        Thread thread = new Thread(runnable);
        thread.start();
        thread.interrupt();
    }
}
