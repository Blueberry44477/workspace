package classical;
import java.util.Queue;

public class Consumer implements Runnable {
    private Queue<Integer> queue;

    public Consumer(Queue<Integer> queue) {
        this.queue = queue;
    }

    @Override
    public void run() {
        while(true) {
            synchronized(queue) {
                while(queue.isEmpty()) {
                    try {
                        System.out.println("Queue is empty.");
                        queue.wait();
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
                
                System.out.println("Removed " + queue.remove() + " from the queue");
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

