import java.util.Set;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.LinkedBlockingQueue;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

class Restaurant {
    private BlockingQueue<Order> orderQueue = new LinkedBlockingQueue<>();
    private Set<Integer> paidClients = ConcurrentHashMap.newKeySet();
    private Lock paymentLock = new ReentrantLock();

    public void placeOrder(Order order) throws InterruptedException {
        orderQueue.put(order);
        System.out.println("Client " + order.getClientId() + " placed an order.");
    }

    public Order takeOrder() throws InterruptedException {
        return orderQueue.take();
    }

    // Клієнти повинні обслуговуватися скоординовано та впорядковано.
    public void processPayment(int clientId) {
        paymentLock.lock();
        try {
            System.out.println("Client " + clientId + " is paying at the checkout...");
            Thread.sleep(200); // Simulate transaction time.
            paidClients.add(clientId);
            System.out.println("Client " + clientId + "'s bill has been successfully paid.");
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        } finally {
            paymentLock.unlock();
        }
    }

    public void exitRestaurant(int clientId) {
        if (!paidClients.contains(clientId)) {
            throw new IllegalStateException("Client " + clientId + " leaves without paying");
        }
        System.out.println("Client " + clientId + " left the restaurant.");
    }
}