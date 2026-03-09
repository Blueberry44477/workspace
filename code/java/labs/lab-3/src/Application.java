package src;

public class Application {
    public static void main(String[] args) {
        add(2, 4);
        add(10.5, 4.2);
    }

    public static void add(int num1, int num2) {
        int result = num1 + num2;
        System.out.println("Result is:" + result);
    }

    public static void add(double num1, double num2) {
        double result = num1 + num2;
        System.out.println("Result is:" + result);
    }

    // public static <T> void show(T item) {
    //     System.out.println(item.toString());
    // }

    public static void show(Object item) {
        System.out.println(item.toString());
    }
}
