package src.task6;

import java.util.List;

public class AreaCalculator {
    public static double calculateTotalArea(List<? extends Shape> shapes) {
        double totalArea = 0.0;
        
        for (Shape shape : shapes)
            totalArea += shape.getArea();
        
        return totalArea;
    }
}
