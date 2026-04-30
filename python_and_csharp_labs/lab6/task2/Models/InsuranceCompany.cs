using System;

namespace task2.Models;

public class InsuranceCompany : IOrganization, IServices
{
    public string Name { get; set; }
    public string Address { get; set; }
    public int Employees { get; set; }
    public string InsuranceType { get; set; }

    public InsuranceCompany(string name, string address, int employees, string insuranceType)
    {
        Name = name;
        Address = address;
        Employees = employees;
        InsuranceType = insuranceType;
    }

    // IOrganization
    public void ShowInfo()
    {
        Console.WriteLine($"[Insurance Company] {Name}, {Address}, Employees: {Employees}");
    }

    public int GetEmployeeCount()
    {
        return Employees;
    }

    // IServices
    public void ProvideService()
    {
        Console.WriteLine($"Providing {InsuranceType} insurance services.");
    }

    public string GetServiceDescription()
    {
        return $"Insurance Type: {InsuranceType}";
    }

    // Own methods
    public double CalculatePremium(double baseAmount)
    {
        return baseAmount * 1.15;
    }

    private static int _policyCounter = 1;

    public string GeneratePolicyNumber()
    {
        string number = $"POL-{_policyCounter:D4}";
        _policyCounter++;
        return number;
    }

}
