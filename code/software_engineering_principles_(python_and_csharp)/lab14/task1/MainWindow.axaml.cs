using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Reflection.Metadata;
using System.Threading;
using Avalonia.Controls;
using Avalonia.Interactivity;
// using System.Threading;

namespace task1;

public partial class MainWindow : Window
{
    public ObservableCollection<int> Numbers { get; set; } = new ObservableCollection<int>();
    private Random random = new Random();
    private Thread generatorThread;
    public MainWindow()
    {
        InitializeComponent();
        this.DataContext = this;
    }

    private async void GenerateNumbersClick(object? sender, RoutedEventArgs e)
    {
        generatorThread = new Thread(GenerateNumbers);
        generatorThread.Start();
    }

    private void GenerateNumbers()
    {
        while (true)
        {
            int randomNumber = random.Next(1, 1000);
            Numbers.Add(randomNumber);
            Thread.Sleep(2000);
        }
    }
}