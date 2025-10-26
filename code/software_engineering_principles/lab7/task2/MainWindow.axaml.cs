using Avalonia.Controls;
using System;
using System.Collections.Generic;
using System.Linq;

namespace task2;
public struct FIRMA
{
    public string NAME { get; set; }
    public string GENDER { get; set; }
    public decimal PLATA { get; set; }
}

public partial class MainWindow : Window
{

    private List<FIRMA> AGENCIJA = new();
    private void UpdateList()
    {
        WorkersList.ItemsSource = AGENCIJA.Select(f => $"{f.NAME} ({f.GENDER}) – {f.PLATA} грн");
    }

    private void ClearInputs()
    {
        NameBox.Text = "";
        GenderBox.Text = "";
        SalaryBox.Text = "";
    }

    private void AddWorker_Click(object? sender, Avalonia.Interactivity.RoutedEventArgs e)
    {
        try
        {
            string name = NameBox.Text?.Trim() ?? "";
            string gender = GenderBox.Text?.Trim() ?? "";
            if (!decimal.TryParse(SalaryBox.Text, out decimal salary))
            {
                ResultBlock.Text = "Enter valid salary.";
                return;
            }

            if (string.IsNullOrWhiteSpace(name) || string.IsNullOrWhiteSpace(gender))
            {
                ResultBlock.Text = "All entries must not be empty.";
                return;
            }

            AGENCIJA.Add(new FIRMA
            {
                NAME = name,
                GENDER = gender,
                PLATA = salary
            });

            UpdateList();
            ClearInputs();
        }
        catch (Exception ex)
        {
            ResultBlock.Text = $"Помилка: {ex.Message}";
        }
    }
    

    private void SortBySalary_Click(object? sender, Avalonia.Interactivity.RoutedEventArgs e)
    {
        AGENCIJA = AGENCIJA.OrderByDescending(f => f.PLATA).ToList();
        UpdateList();
        ResultBlock.Text = "Sorted in descending salary.";
    }

    private void ShowMaxSalary_Click(object? sender, Avalonia.Interactivity.RoutedEventArgs e)
    {
        if (AGENCIJA.Count == 0)
        {
            ResultBlock.Text = "List is Empty.";
            return;
        }

        decimal maxSalary = AGENCIJA.Max(f => f.PLATA);
        var topWorkers = AGENCIJA.Where(f => f.PLATA == maxSalary).ToList();

        string result = $"Max Salary: {maxSalary}\n";
        foreach (var w in topWorkers)
            result += $"- {w.NAME} ({w.GENDER}), {w.PLATA}\n";

        ResultBlock.Text = result;
    }

    public MainWindow()
    {
        InitializeComponent();
    }
}