public class Order {
    private final int clientId;
    private boolean isServed = false;

    public Order(int clientId) {
        this.clientId = clientId;
    }

    public int getClientId() {
        return clientId;
    }

    public synchronized void markServed() {
        this.isServed = true;
        this.notify(); // Wakes up the waiting client thread
    }

    public synchronized void awaitService() throws InterruptedException {
        while (!isServed) {
            this.wait(); 
        }
    }
}