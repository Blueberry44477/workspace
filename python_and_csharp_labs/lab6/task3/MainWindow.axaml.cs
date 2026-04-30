using Avalonia.Controls;
using task3.Models;
using System;
using System.Linq;

namespace task3;

public partial class MainWindow : Window
{
    private readonly PlaneCollection _planes = new();

    public MainWindow()
    {
        InitializeComponent();
    }

    private void AddPlane_Click(object? sender, Avalonia.Interactivity.RoutedEventArgs e)
    {
        string model = ModelBox.Text ?? "";
        if (!int.TryParse(HoursBox.Text, out int hours) ||
            !double.TryParse(ReliabilityBox.Text, out double reliability))
        {
            return;
        }

        var plane = new Plane(model, hours, reliability);
        _planes.Add(plane);

        RefreshList(_planes.ToArray());
        ClearInput();
    }

    private void SortComparable_Click(object? sender, Avalonia.Interactivity.RoutedEventArgs e)
    {
        var sorted = _planes.ToArray();
        Array.Sort(sorted); // Uses IComparable
        RefreshList(sorted);
    }

    private void SortComparer_Click(object? sender, Avalonia.Interactivity.RoutedEventArgs e)
    {
        var sorted = _planes.ToArray();
        Array.Sort(sorted, new PlaneComparer()); // Uses IComparer
        RefreshList(sorted);
    }

    private void RefreshList(Plane[] planes)
    {
        PlaneList.ItemsSource = planes.Select(p => p.ToString()).ToList();
    }

    private void ClearInput()
    {
        ModelBox.Text = "";
        HoursBox.Text = "";
        ReliabilityBox.Text = "";
    }
}
