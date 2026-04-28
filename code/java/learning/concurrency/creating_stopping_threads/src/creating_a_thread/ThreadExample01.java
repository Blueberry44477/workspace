package creating_a_thread;
public class ThreadExample01 {
    public static class MyThread extends Thread {
        public void run() {
            System.out.println("Hello from thread.");
        }
    }
    public static void main(String[] args) {
        MyThread thread = new MyThread();
        thread.run();
    }
}
