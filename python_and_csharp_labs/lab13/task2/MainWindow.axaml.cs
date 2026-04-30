using Avalonia.Controls;
using Avalonia.Interactivity;
using Microsoft.Recognizers.Text;
using Microsoft.Recognizers.Text.Number;
using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;

namespace task2;

public partial class MainWindow : Window
{
    private async void LoadButton_Click(object? sender, RoutedEventArgs e)
    {
        var dialog = new OpenFileDialog();
        dialog.Filters.Add(new FileDialogFilter { Name = "Text", Extensions = {"txt"} });
        var result = await dialog.ShowAsync(this);
        if (result != null && result.Length > 0)
        {
            InputTextBox.Text = File.ReadAllText(result[0]);
            OutputBox.Text = "";
        }
    }

    private void RecognizeButton_Click(object? sender, RoutedEventArgs e)
    {
        string input = InputTextBox.Text ?? "";
        OutputBox.Text = "";

        // Found numbers with fields: Start, End, Text.
        List<ModelResult> results = NumberRecognizer.RecognizeOrdinal(input, Culture.English);

        // Update OutputBox.Text
        OutputBox.Text += $"Ordinal Count: {results.Count()}\n";
        foreach (var result in results)
            OutputBox.Text += $"{result.Text} - {result.Resolution["value"]}\n";

        var ordered = results.OrderByDescending(r => r.Start);
        string modified = input;

        // Change string numbers in input text to integers from end to start.
        foreach (var result in ordered)
        {
            string value = result.Resolution["value"].ToString();
            modified = modified.Remove(result.Start, result.Text.Length)
                                .Insert(result.Start, value);
        }

        OutputTextBox.Text = modified;
    }

    private async void SaveButton_Click(object? sender, RoutedEventArgs e)
    {
        var dialog = new SaveFileDialog();
        dialog.Filters.Add(new FileDialogFilter { Name = "Text", Extensions = { "txt" } });

        var path = await dialog.ShowAsync(this);
        if (path != null)
            File.WriteAllText(path, OutputTextBox.Text);
    }
    public MainWindow()
    {
        InitializeComponent();
    }
}