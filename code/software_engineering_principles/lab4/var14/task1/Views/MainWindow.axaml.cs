using Avalonia.Controls;
using Avalonia.Interactivity;
using System;
using System.Collections.Generic;
using System.IO;

namespace task1.Views;

public partial class MainWindow : Window
{
    // private List<string[]> _buildings = new();
    private string[,] _buildings;

    public MainWindow()
    {
        InitializeComponent();
    }

    private async void OnBrowseClick(object? sender, RoutedEventArgs e)
    {
        var dialog = new OpenFileDialog
        {
            Title = "Choose input file",
            AllowMultiple = false
        };

        var result = await dialog.ShowAsync(this);
        if (result != null && result.Length > 0)
        {
            string path = result[0];

            string fileContent = File.ReadAllText(path);
            InputTextBox.Text = fileContent;

            LoadData(path);

            ShowFiltered();
        }
    }

    private void LoadData(string path)
    {
        string[] lines = File.ReadAllLines(path);

        int rows = lines.Length;
        int columns = 6;

        _buildings = new string[rows, columns];

        for (int i = 0; i < rows; i++)
        {
            string[] parts = lines[i].Split(',', StringSplitOptions.TrimEntries);

            if (parts.Length == columns)
            {
                for (int j = 0; j < columns; j++)
                {
                    _buildings[i, j] = parts[j];
                }
            }
        }
    }
    private void ShowFiltered()
    {
        if (_buildings == null)
            return;

        OutputTextBox.Text = "";

        int rows = _buildings.GetLength(0);
        int cols = _buildings.GetLength(1);

        for (int i = 0; i < rows; i++)
        {
            // Filter Lifetime
            if (int.TryParse(_buildings[i, 4], out int lifetime) && lifetime > 50)
            {
                string[] lineParts = new string[cols];
                for (int j = 0; j < cols; j++)
                {
                    lineParts[j] = _buildings[i, j];
                }
                string line = string.Join(", ", lineParts);
                OutputTextBox.Text += line + Environment.NewLine;
            }
        }
    }

    private async void OnSaveClick(object? sender, RoutedEventArgs e)
    {
        var dialog = new SaveFileDialog
        {
            Title = "Save Result",
            InitialFileName = "Output Data.txt"
        };

        var path = await dialog.ShowAsync(this);
        if (!string.IsNullOrWhiteSpace(path))
        {
            File.WriteAllText(path, OutputTextBox.Text);
        }
    }
}
