public class Waiter implements Runnable {
    private final int waiterId;
    private final Restaurant restaurant;

    public Waiter(int waiterId, Restaurant restaurant) {
        this.waiterId = waiterId;
        this.restaurant = restaurant;
    }

    @Override
    public void run() {
        try {
            while (!Thread.currentThread().isInterrupted()) {
                Order order = restaurant.takeOrder();
                System.out.println("Waiter " + waiterId + 
                    " took the order from Client " + order.getClientId());
                
                // Simulate preparation and serving of the dish
                Thread.sleep(500); 
                System.out.println("Waiter " + waiterId + 
                    " served the dish to Client " + order.getClientId());
                
                // Notify the client that their order is fulfilled
                order.markServed();
            }
        } catch (InterruptedException e) {
            System.out.println("Waiter " + waiterId + " is ending the shift.");
            Thread.currentThread().interrupt();
        }
    }
}