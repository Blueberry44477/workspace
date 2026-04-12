package classical;
import java.util.Queue;

public class Producer implements Runnable {
    private Queue<Integer> queue;
    private Integer capacity;

    public Producer(Queue<Integer> queue, Integer capacity) {
        this.queue = queue;
        this.capacity = capacity;
    }

    @Override
    public void run() {
        while(true) {
            synchronized(queue) {
                while(queue.size() == capacity) {
                    try {
                        System.out.println("Queue is full.");
                        queue.wait();
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }

                queue.add(10);
                System.out.println("Added 10 to the queue.");
                queue.notifyAll();

                try {
                    Thread.sleep(2000); 
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}
