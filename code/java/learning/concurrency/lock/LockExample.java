import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class LockExample {
    public static void main(String[] args) {
        Lock lock = new ReentrantLock();
        try {
            lock.lock();
            //
        } finally {
            lock.unlock();
        }
    }
}
