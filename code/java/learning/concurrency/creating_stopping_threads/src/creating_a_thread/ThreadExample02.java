package creating_a_thread;
public class ThreadExample02 {
    public static class MyRunnable implements Runnable {
        @Override
        public void run() {
            System.out.println("Hello from thread.");
        }
    }
    public static void main(String[] args) {
        Thread thread = new Thread(new MyRunnable(), "Thread from runnable");
        thread.start();
    }
}
