package src.task3;

import java.util.NoSuchElementException;

public class Box<T> {
    private T content;
    private boolean isEmpty = true;

    public void put(T item) {
        this.content = item;
        this.isEmpty = false;
    }

    public T take() {
        if (isEmpty) {
            throw new NoSuchElementException("Box is empty");
        }

        T item = content;
        content = null;
        isEmpty = true;
        return item;
    }

    public boolean isEmpty() {
        return isEmpty;
    }
}
