public class Main {
    public static void main(String[] args) {
        Runnable runnable01 = new MyRunnable();
        Runnable runnable02 = new MyRunnable();

        Thread thread01 = new Thread(runnable01);
        Thread thread02 = new Thread(runnable02);

        thread01.start();
        thread02.start();
    }
}
