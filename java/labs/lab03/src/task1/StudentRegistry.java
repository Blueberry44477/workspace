package src.task1;
import java.util.HashMap;
import java.util.Map;
import java.util.NoSuchElementException;


public class StudentRegistry {
    private Map<Integer, Student> students = new HashMap<>();

    public void addStudent(Student student) {
        students.put(student.getId(), student);
    }

    public void removeStudent(int id) {
        if (students.remove(id) == null)
            throw new NoSuchElementException("Student with ID " + id + " not found.");
    }

    public Student findStudent(Integer id) {
        return students.get(id);
    }

    public void displayAll() {
        if (students.isEmpty())
            throw new Error("No students to display.");

        for (Student s : students.values())
            System.out.println(s);
    }
}