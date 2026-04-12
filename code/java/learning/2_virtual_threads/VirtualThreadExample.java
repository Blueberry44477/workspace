public class VirtualThreadExample {
    public static void main(String[] args) 
    {
        Runnable runnable = () -> {
            for (int i = 0; i < 5; i++) {
                System.out.println("Index: " + i);
            }
        };

        // Immediately started thread.
        Thread vThread01 = Thread.ofVirtual().start(runnable);

        // Unstarted Thread.
        Thread vUnstartedThread = Thread.ofVirtual().unstarted(runnable);
        vUnstartedThread.start();
    }
}
