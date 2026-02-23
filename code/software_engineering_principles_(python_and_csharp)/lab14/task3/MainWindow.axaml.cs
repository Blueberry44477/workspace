using System;
using System.Threading;
using System.Threading.Tasks;
using Avalonia.Controls;
using Avalonia.Interactivity;
using Avalonia.Threading;

namespace task3;

public partial class MainWindow : Window
{
    public MainWindow()
    {
        InitializeComponent();
    }
    private async void StartProgressClick(object? sender, RoutedEventArgs e)
    {
        ProgressBar.Value = 0;
        for (int progress = 0; progress <= 100; progress++)
        {
            ProgressBar.Value++;
            await Task.Delay(50);
        }
    }
}