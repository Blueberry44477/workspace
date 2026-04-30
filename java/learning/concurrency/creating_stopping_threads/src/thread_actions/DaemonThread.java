package thread_actions;

public class DaemonThread {
    public static void main(String[] args) {
        Runnable runnable = () -> {
            while(true) {
                try {
                    System.out.println("My Thread is Running");
                    Thread.sleep(100);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        };
        Thread thread = new Thread(runnable);
        thread.setDaemon(true);
        thread.start();
    }
}
