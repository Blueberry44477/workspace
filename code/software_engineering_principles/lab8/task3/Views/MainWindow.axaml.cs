using Avalonia.Controls;

using task3.ViewModels;

namespace task3.Views;

public partial class MainWindow : Window
{

    private readonly RainbowQuiz _quiz = new();
    public MainWindow()
    {
        InitializeComponent();
    }
    private async void OnCheckClick(object? sender, Avalonia.Interactivity.RoutedEventArgs e)
    {
        string input = ColorInput.Text?.Trim() ?? "";
        if (string.IsNullOrWhiteSpace(input))
        {
            ResultText.Text = "Enter One of the rainbow colors!";
            return;
        }
        string result = _quiz.GetColorInfo(input);
        ResultText.Text = result;

    }
}