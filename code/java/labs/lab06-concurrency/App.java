import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

public class App {
    public static void main(String[] args) {
        Restaurant restaurant = new Restaurant();
        
        int numberOfWaiters = 3;
        int numberOfClients = 10;

        ExecutorService waitersPool = Executors.newFixedThreadPool(numberOfWaiters);
        ExecutorService clientsPool = Executors.newFixedThreadPool(numberOfClients);

        // Start waiter threads.
        for (int i = 1; i <= numberOfWaiters; i++) {
            waitersPool.execute(new Waiter(i, restaurant));
        }

        // Start client threads with a slight delay to simulate gradual arrival
        for (int i = 1; i <= numberOfClients; i++) {
            try {
                Thread.sleep(150);
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
            clientsPool.execute(new Client(i, restaurant));
        }

        // Shutdown the clients pool
        clientsPool.shutdown();
        try {
            // Wait for all clients to finish
            if (clientsPool.awaitTermination(10, TimeUnit.SECONDS)) {
                System.out.println("All clients have been served.");
            }
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }

        // Shutdown the waiters pool (interrupts the infinite loop)
        waitersPool.shutdownNow();
    }
}