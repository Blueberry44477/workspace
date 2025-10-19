using System.Collections.Generic;

namespace task3.Models;

public class PlaneComparer : IComparer<Plane>
{
    public int Compare(Plane? x, Plane? y)
    {
        if (x == null || y == null) return 0;

        int hourComparison = x.FlightHours.CompareTo(y.FlightHours);
        if (hourComparison != 0)
            return hourComparison;

        return y.Reliability.CompareTo(x.Reliability); 
        // Descending reliability: higher first
    }
}
