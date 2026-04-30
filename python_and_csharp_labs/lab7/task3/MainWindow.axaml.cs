using Avalonia.Controls;
using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;

namespace task3;
public struct ServerReboot
{
    public DateTime DateTime;
    public string Reason;
    public string User;
}
public partial class MainWindow : Window
{
    private readonly List<ServerReboot> log = new();
    private void AddReboot_Click(object? sender, Avalonia.Interactivity.RoutedEventArgs e)
    {
        try
        {
            string dateString = DateBox.Text?.Trim() ?? "";
            string timeString = TimeBox.Text?.Trim() ?? "";
            string reason = (ReasonBox.SelectedItem as ComboBoxItem)?.Content?.ToString() ?? "";
            string user = UserBox.Text?.Trim() ?? "";

            DateTime date = DateTime.ParseExact($"{dateString} {timeString}", "ddMMyyyy HH:mm:ss", CultureInfo.InvariantCulture);

            log.Add(new ServerReboot { DateTime = date, Reason = reason, User = user });

            LogList.ItemsSource = log.Select(x => $"{x.DateTime:dd.MM.yyyy HH:mm:ss} | {x.Reason} | {x.User}");
        }
        catch
        {
            ShowMessage("Date Error.");
        }
    }
    private void ShowAll_Click(object? sender, Avalonia.Interactivity.RoutedEventArgs e)
    {
        DateTime now = DateTime.Now;
        LogList.ItemsSource = log.Select(x =>
        {
            double days = (now - x.DateTime).TotalDays;
            return $"{x.DateTime:dd.MM.yyyy HH:mm:ss} | {x.Reason} | {x.User} | passed days: {days:F0}";
        });
    }
    
    private void NightBtn_Click(object? sender, Avalonia.Interactivity.RoutedEventArgs e)
    {
        var night = log.Where(x => x.DateTime.Hour >= 22 || x.DateTime.Hour < 6);
        LogList.ItemsSource = night.Select(x => $"{x.DateTime:dd.MM.yyyy HH:mm:ss} | {x.Reason} | {x.User}");
    }

    private void LastBtn_Click(object? sender, Avalonia.Interactivity.RoutedEventArgs e)
    {
        if (log.Count == 0)
        {
            ShowMessage("Log is Empty.");
            return;
        }

        var last = log.OrderByDescending(x => x.DateTime).First();
        ShowMessage($"Last Reboot:\n{last.DateTime:dd.MM.yyyy HH:mm:ss}\n{last.Reason}\n{last.User}");
    }

    private async void FilterBetweenBtn_Click(object? sender, Avalonia.Interactivity.RoutedEventArgs e)
    {
        var startBox = new TextBox { Watermark = "Start Date (DDMMYYYY):" };
        var endBox = new TextBox { Watermark = "End Date (DDMMYYYY):" };
        var okBtn = new Button { Content = "OK", HorizontalAlignment = Avalonia.Layout.HorizontalAlignment.Center };

        var dialog = new Window
        {
            Width = 350,
            Height = 180,
            Title = "Date Entry",
            Content = new StackPanel
            {
                Margin = new Avalonia.Thickness(15),
                Spacing = 10,
                Children =
                {
                    new TextBlock { Text = "Введіть діапазон дат для перевірки:" },
                    startBox,
                    endBox,
                    okBtn
                }
            }
        };

        okBtn.Click += (_, __) => dialog.Close(true);

        var result = await dialog.ShowDialog<bool>(this);
        if (!result)
            return;

        try
        {
            DateTime startDate = DateTime.ParseExact(startBox.Text!.Trim(), "ddMMyyyy", null);
            DateTime endDate = DateTime.ParseExact(endBox.Text!.Trim(), "ddMMyyyy", null);

            int count = log.Count(x =>
                x.Reason.Equals("Service", StringComparison.OrdinalIgnoreCase) &&
                x.DateTime.Date >= startDate.Date &&
                x.DateTime.Date <= endDate.Date);

            await new Window
            {
                Width = 320,
                Height = 120,
                Title = "Result",
                Content = new TextBlock
                {
                    Text = $"Reboots via Service:\n{count}",
                    VerticalAlignment = Avalonia.Layout.VerticalAlignment.Center,
                    HorizontalAlignment = Avalonia.Layout.HorizontalAlignment.Center,
                    TextAlignment = Avalonia.Media.TextAlignment.Center
                }
            }.ShowDialog(this);
        }
        catch
        {
            await new Window
            {
                Width = 300,
                Height = 100,
                Title = "Error",
                Content = new TextBlock
                {
                    Text = "Wrong Date Format.",
                    VerticalAlignment = Avalonia.Layout.VerticalAlignment.Center,
                    HorizontalAlignment = Avalonia.Layout.HorizontalAlignment.Center,
                    TextAlignment = Avalonia.Media.TextAlignment.Center
                }
            }.ShowDialog(this);
        }
    }
    
    private async void ShowByDateBtn_Click(object? sender, Avalonia.Interactivity.RoutedEventArgs e)
    {
        if (log.Count == 0)
        {
            ShowMessage("No Data");
            return;
        }
            
        var dateBox = new TextBox { Watermark = "Enter Date (DDMMYYYY))" };
        var okBtn = new Button { Content = "OK", HorizontalAlignment = Avalonia.Layout.HorizontalAlignment.Center };

        var dialog = new Window
        {
            Width = 300,
            Height = 120,
            Title = "Search By Date",
            Content = new StackPanel
            {
                Margin = new Avalonia.Thickness(15),
                Spacing = 10,
                Children = { dateBox, okBtn }
            }
        };

        okBtn.Click += (_, __) => dialog.Close(true);

        var result = await dialog.ShowDialog<bool>(this);
        if (!result) return;

        try
        {
            DateTime searchDate = DateTime.ParseExact(dateBox.Text!.Trim(), "ddMMyyyy", null);

            var entries = log.Where(log => log.DateTime.Date == searchDate.Date).ToList();

            if (entries.Count == 0)
            {
                ShowMessage("No Entries");
            }
            LogList.ItemsSource = entries.Select(x => $"{x.DateTime:dd.MM.yyyy HH:mm:ss} | {x.Reason} | {x.User}");
        }
        catch
        {
            ShowMessage("Wrong Date Format.");
        }
    }


    private async void ShowMessage(string message)
    {
        var dialog = new Window
        {
            Width = 400,
            Height = 200,
            Content = new TextBlock
            {
                Text = message,
                TextWrapping = Avalonia.Media.TextWrapping.Wrap,
                Margin = new Avalonia.Thickness(20)
            }
        };
        await dialog.ShowDialog(this);
    }
    public MainWindow()
    {
        InitializeComponent();
    }
}