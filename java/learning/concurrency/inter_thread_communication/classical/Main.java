package classical;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    public static void main(String[] args) {
        Queue<Integer> queue = new LinkedList<>();
        Integer queueCapacity = 10;

        Thread producerThread = new Thread(new Producer(queue, queueCapacity));
        Thread consumerThread = new Thread(new Consumer(queue));

        producerThread.start();
        consumerThread.start();
    }
}
