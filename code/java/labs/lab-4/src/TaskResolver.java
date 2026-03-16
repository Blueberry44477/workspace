import java.util.Optional;
import java.util.Set;
import java.util.function.Function;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;
import java.util.Map;

public class TaskResolver {
    public class Employee {
        private String name;
        private int salary;
        
        public Employee(String name, int salary) {
            this.name = name;
            this.salary = salary;
        }
        
        public int getSalary() { return salary; }
        public String getName() { return name; }
    }
    
    public class Person {
        private String name;
        private List<Person> friends;

        public Person(String name, List<Person> friends) {
            this.name = name;
            this.friends = friends;
        }

        public String getName() { return name; }
        public List<Person> getFriends() { return friends; }
    }

    public class Transaction {
        private double sum;
        private String category;
        
        public Transaction(double sum, String category) {
            this.sum = sum;
            this.category = category;
        }
        
        public double getSum() { return sum; }
        public String getCategory() { return category; }
    }

    public static Optional<String> firstTask(List<String> list) {

        return list.stream()
            .filter(str -> str.startsWith("X"))
            .filter(str -> str.length() > 5)
            .findFirst()
            .or(() -> Optional.of("Default"));
    }

    // Звести список до списку цілих чисел.
    public static List<Integer> secondTask(List<Optional<Integer>> list) {

        // return list.stream()
        //     .filter(Optional::isPresent)
        //     .map(Optional::get)
        //     .collect(Collectors.toList());
        
        return list.stream()
            .flatMap(Optional::stream)
            .collect(Collectors.toList());
    }

    // Find Longest String.
    public static Optional<String> thirdTask(List<String> names) {
        return names.stream().max(Comparator.comparingInt(String::length));
    }

    public static Map<String, Optional<Employee>> fourthTask(List<Employee> employees) {
        return employees.stream()
            .collect(Collectors.groupingBy(
                employee -> {
                    if (employee.getSalary() < 3000) return "< 3000";
                    if (employee.getSalary() <= 5000) return "3000–5000";
                    return "> 5000";
                },
                Collectors.maxBy(Comparator.comparingInt(Employee::getSalary))
            ));
    }

    public static Optional<Integer> fifthTask(List<Integer> numbers) {
        return numbers.stream()
            .filter(n -> n % 2 != 0)
            .reduce((a, b) -> a * b);
    }

    public static List<String> sixthTask(List<Person> people) {
        return people.stream()
                     .map(Person::getFriends)
                     .flatMap(List::stream)
                     .map(Person::getName)
                     .map(String::toUpperCase)
                     .distinct()
                     .collect(Collectors.toList());
    }

    public void seventhTask() {
        List<Transaction> transactions = Arrays.asList(
            new Transaction(100, "Food"),
            new Transaction(10, "Transport")

        );

        Set<String> targetCategories = Set.of("Food", "Tech");

        Function<List<Transaction>, Map<String, Double>> classifier = list -> list.stream()
            .filter(t -> targetCategories.contains(t.getCategory()))
            .collect(Collectors.groupingBy(
                    Transaction::getCategory,
                    Collectors.summingDouble(Transaction::getSum)
        ));
        
        Map<String, Double> result = classifier.apply(transactions);
    }

}
