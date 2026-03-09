package src.task4;

import java.util.NoSuchElementException;

public class Math {
    public static <T extends Comparable<T>> T findMax(T[] array) {
        if (array == null || array.length == 0)
            throw new NoSuchElementException("Array is null || empty.");

        T max = array[0];

        for (int i = 1; i < array.length; i++)
            if (array[i].compareTo(max) > 0)
                max = array[i];

        return max;
    }
}
