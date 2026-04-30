package thread_actions;

public class ThreadJoin {
    public static void main(String[] args) {
        Runnable runnable = () -> {
            for (int i = 0; i < 5; i++) {
                try {
                    System.out.println("My Thread is Running");
                    Thread.sleep(200);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        };
        Thread thread = new Thread(runnable);
        thread.setDaemon(true);
        thread.start();

        try { thread.join(); } catch (InterruptedException e) { e.printStackTrace(); }
    }
}
