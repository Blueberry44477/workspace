import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class SharedClass {
    Lock lockObject = new ReentrantLock();

    public void methodA() {
        lockObject.lock(); // (1) Потік бере замок (лічильник = 1)
        try {
            System.out.println("Виконую methodA");
            methodB();     // (2) Виклик іншого методу, який теж хоче замок
        } finally {
            lockObject.unlock(); // (4) Відпускає замок (лічильник стає 0)
        }
    }

    public void methodB() {
        lockObject.lock(); // (3) ОСЬ ТУТ МАГІЯ: Потік не чекає, бо він ВЖЕ власник!
        try {
            System.out.println("Виконую methodB");
        } finally {
            lockObject.unlock(); // Лічильник стає 1
        }
    }
}