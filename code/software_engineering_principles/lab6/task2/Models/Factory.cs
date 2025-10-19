using System;

namespace task2.Models;

public class Factory : IOrganization, IServices
{
    public string Name { get; set; }
    public string Address { get; set; }
    public int Employees { get; set; }
    public string ProductType { get; set; }

    public Factory(string name, string address, int employees, string productType)
    {
        Name = name;
        Address = address;
        Employees = employees;
        ProductType = productType;
    }

    // IOrganization
    public void ShowInfo()
    {
        Console.WriteLine($"[Factory] {Name}, {Address}, Employees: {Employees}");
    }

    public int GetEmployeeCount()
    {
        return Employees;
    }

    // IServices
    public void ProvideService()
    {
        Console.WriteLine($"Manufacturing {ProductType}.");
    }

    public string GetServiceDescription()
    {
        return $"Product Type: {ProductType}";
    }

    // Own methods
    public int CalculateProduction(int hours, int outputPerHour)
    {
        return hours * outputPerHour;
    }

    public string ScheduleMaintenance(string machineName)
    {
        return $"Maintenance scheduled for {machineName} tomorrow.";
    }
}
