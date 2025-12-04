using System;
using System.Collections.ObjectModel;
using System.Threading;
using System.Threading.Tasks;
using Avalonia.Controls;
using Avalonia.Threading;
using Avalonia.Interactivity;

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

    private void GenerateNumbersClick(object? sender, RoutedEventArgs e)
    {
        Task.Run(async() => 
        {
            while (true)
            {
                int randomNumber = random.Next(1, 1000);
                Numbers.Add(randomNumber);
                Thread.Sleep(2000);
            }
        });
    }
}