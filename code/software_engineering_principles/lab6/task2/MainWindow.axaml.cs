using Avalonia.Controls;
using task2.Models;
using System;

namespace task2;

public partial class MainWindow : Window
{
    private void Create_Click(object? sender, Avalonia.Interactivity.RoutedEventArgs e)
    {
        string name = NameBox.Text ?? "";
        string address = AddressBox.Text ?? "";
        int employees = int.TryParse(EmployeesBox.Text, out int num) ? num : 0;
        string special = SpecialBox.Text ?? "";

        var selectedType = (TypeBox.SelectedItem as ComboBoxItem)?.Content?.ToString();

        if (string.IsNullOrWhiteSpace(name) || string.IsNullOrWhiteSpace(address) || string.IsNullOrWhiteSpace(special))
        {
            Output.Text = "Please fill in all fields.";
            return;
        }

        if (selectedType == "Insurance Company")
        {
            var company = new InsuranceCompany(name, address, employees, special);
            Output.Text =
                $"Created Insurance Company:\n" +
                $"{company.Name}, {company.Address}\n" +
                $"Employees: {company.GetEmployeeCount()}\n" +
                $"{company.GetServiceDescription()}\n" +
                $"Premium: {company.CalculatePremium(1000):C}\n" +
                $"Policy #: {company.GeneratePolicyNumber()}";
        }
        else if (selectedType == "Factory")
        {
            var factory = new Factory(name, address, employees, special);
            Output.Text =
                $"Created Factory:\n" +
                $"{factory.Name}, {factory.Address}\n" +
                $"Employees: {factory.GetEmployeeCount()}\n" +
                $"{factory.GetServiceDescription()}\n" +
                $"Production (8h x 50): {factory.CalculateProduction(8, 50)} units\n" +
                $"{factory.ScheduleMaintenance("Main Machine")}";
        }
        else
        {
            Output.Text = "Please select a valid organization type.";
        }
    }    
    public MainWindow()
    {
        InitializeComponent();
    }
}