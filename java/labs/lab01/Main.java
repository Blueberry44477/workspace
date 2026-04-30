// Var 14
import java.util.HashMap;

public class Main {
    public static void main(String[] args) {
        // Завдання 1. Заміна двох чисел за допомогою тимчасової змінної.
        System.out.println("Task 1");
        int a = 10;
        int b = 20;
        System.out.println("a: " + a);
        System.out.println("b: " + b + '\n');
        
        int temp = a;
        a = b;
        b = temp;
        
        System.out.println("a: " + a);
        System.out.println("b: " + b);

        // Завдання 2. Програма для перевірки довжини пароля.
        System.out.println("\nTask 2");
        final int MIN_LENGTH = 16;
        final int MAX_LENGTH = 256;

        String password = "tenSymbols";
        final int PASSWORD_LENGTH = password.length();

        if (PASSWORD_LENGTH < MIN_LENGTH)
            System.out.println("Password is too short.");
        else if (PASSWORD_LENGTH > MAX_LENGTH)
            System.out.println("Password is too long");
        else
            System.out.println("Password Length: " + password.length());

        // Завдання 3. Програма для друку назви місяця на основі введеного користувачем числа.
        System.out.println("Task 3");
        int monthNumber = 10;

        switch(monthNumber) {
            case 1:
                System.out.println("Січень");
                break;
            case 2:
                System.out.println("Лютий");
                break;
            case 3:
                System.out.println("Березень");
                break;
            case 4:
                System.out.println("Квітень");
                break;
            case 5:
                System.out.println("Травень");
                break;
            case 6:
                System.out.println("Червень");
                break;
            case 7:
                System.out.println("Липень");
                break;
            case 8:
                System.out.println("Серпень");
                break;
            case 9:
                System.out.println("Вересень");
                break;
            case 10:
                System.out.println("Жовтень");
                break;
            case 11:
                System.out.println("Листопад");
                break;
            case 12:
                System.out.println("Грудень");
                break;
            default:
                System.out.println("Інвалід");
                break;
        }

        // Завдання 4. Написати програму, яка знаходить суму всіх непарних чисел до заданого числа.
        System.out.println("\nTask 4");
        int inputNumber = 5;
        int currentNumber = 1;
        int oddSum = 0;

        while(currentNumber <= inputNumber) {
            oddSum += currentNumber;
            currentNumber += 2;
        }
        System.out.println("Sum = " + oddSum);
            
        
        // Завдання 5. Цикл for. Визначення частоти кожного символу в рядку.
        String input = "interesting";
        var charFrequency = countCharacterFrequency(input);
        display(charFrequency);
    }
    
    // Завдання 5. Цикл for. Визначення частоти кожного символу в рядку.
    public static HashMap<Character, Integer> countCharacterFrequency(String input) {
        HashMap<Character, Integer> chars = new HashMap<>();
        for (int i = 0; i < input.length(); i++) {
            char symbol = input.charAt(i);

            if (chars.containsKey(symbol))
                chars.put(symbol, chars.get(symbol) + 1);
            else
                chars.put(symbol, 1);
        }
        return chars;
    }

    public static void display(HashMap<Character, Integer> input) {
        for (Character key : input.keySet())
            System.out.println(key + " : " + input.get(key));
    }


}