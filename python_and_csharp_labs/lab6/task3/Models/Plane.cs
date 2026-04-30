using System;
using System.Collections;
using System.Collections.Generic;

namespace task3.Models;

public class Plane : IComparable<Plane>
{
    public string Model { get; set; }
    public int FlightHours { get; set; }
    public double Reliability { get; set; } // 0.0 - 1.0

    public Plane(string model, int flightHours, double reliability)
    {
        Model = model;
        FlightHours = flightHours;
        Reliability = reliability;
    }

    public override string ToString()
    {
        return $"{Model} | Hours: {FlightHours} | Reliability: {Reliability:F2}";
    }

    // IComparable — compare by flight hours
    public int CompareTo(Plane? other)
    {
        if (other == null) 
            return 1;
        return FlightHours.CompareTo(other.FlightHours);
    }
}
