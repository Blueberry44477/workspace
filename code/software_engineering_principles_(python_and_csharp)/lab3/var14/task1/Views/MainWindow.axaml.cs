using Avalonia.Controls;
using Avalonia.Interactivity;
using System.Collections.Generic;
using System.Globalization;

namespace task1.Views;

public partial class MainWindow : Window
{
    private static readonly CultureInfo Ukranian = new("uk-UA");
    private static readonly HashSet<char> Consonants = new()
    {
        'б','в','г','ґ','д','ж','з','й','к','л','м','н','п','р','с','т','ф','х','ц','ч','ш','щ'
    };

    private int CountConsonants(string text)
    {
        int count = 0;
        foreach (var symbol in text)
        {
            if (Consonants.Contains(char.ToLower(symbol, Ukranian)))
                count++;
        }
        return count;
    }
    private void OnClick(object? sender, RoutedEventArgs e)
    {
        var input = this.FindControl<TextBox>("InputBox").Text ?? string.Empty;
        int count = CountConsonants(input);
        this.FindControl<TextBlock>("ConsonantsCount").Text = $"Приголосних: {count}";
    }
    public MainWindow()
    {
        InitializeComponent();
        CountConsonantsButton.Click += OnClick;
    }
}