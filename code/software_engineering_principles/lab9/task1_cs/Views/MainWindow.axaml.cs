using Avalonia.Controls;
using task1_cs.ViewModels;

namespace task1_cs.Views;

public partial class MainWindow : Window
{
    public MainWindow()
    {
        InitializeComponent();
    }
    private MainWindowViewModel VM = new MainWindowViewModel();

    private void LoadButton_Click(object sender, Avalonia.Interactivity.RoutedEventArgs e)
    {
        VM.InputFilePath = InputPathTextBox.Text;
        VM.LoadFile();
        L1ItemsControl.ItemsSource = VM.List1;
    }

    private void ProcessButton_Click(object sender, Avalonia.Interactivity.RoutedEventArgs e)
    {
        VM.ProcessLetters();
        L2ItemsControl.ItemsSource = VM.List2;
    }

    private void SaveButton_Click(object sender, Avalonia.Interactivity.RoutedEventArgs e)
    {
        VM.OutputFilePath = OutputPathTextBox.Text;
        VM.SaveFile();
    }
}