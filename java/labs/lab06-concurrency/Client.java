class Client implements Runnable {
    private final int clientId;
    private final Restaurant restaurant;

    public Client(int clientId, Restaurant restaurant) {
        this.clientId = clientId;
        this.restaurant = restaurant;
    }

    @Override
    public void run() {
        try {
            System.out.println("Client " + clientId + " entered the restaurant.");
            Order order = new Order(clientId);
            
            restaurant.placeOrder(order);
            
            // The client waits until the waiter calls order.markServed().
            order.awaitService();
            
            System.out.println("Client " + clientId + " is eating.");
            Thread.sleep(800); // Simulate eating time.
            
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        } finally {
            restaurant.processPayment(clientId);
            restaurant.exitRestaurant(clientId);
        }
    }
}