using System;
using System.Net.NetworkInformation;
using System.Threading;
using Avalonia.Controls;
using Avalonia.Interactivity;
using Avalonia.Threading;

namespace task4;

public partial class MainWindow : Window
{
    public MainWindow()
    {
        InitializeComponent();
    }

    public void ScanClick(object? sender, RoutedEventArgs e)
    {
        OutputTextBox.Text = "";

        string subnet = InputTextBox.Text?.Trim() ?? "";
        if (string.IsNullOrWhiteSpace(subnet))
        {
            OutputTextBox.Text = "Empty.";
            return;
        }

        // Example: "172.20.10."
        if (!subnet.EndsWith(".")) subnet += ".";
        for (int i = 1; i < 255; i++)
        {
            Thread thread = new Thread(() => Function(subnet, i));
            thread.Start();
        }
    }

    private void Function(string subnet, int host)
    {
        string ip = subnet + host;
        System.Net.NetworkInformation.Ping ping =
            new System.Net.NetworkInformation.Ping();
        System.Net.NetworkInformation.PingReply pingReply =
        ping.Send(ip, 1000);

        if (pingReply.Status.ToString().Equals("Success"))
        {
            Dispatcher.UIThread.InvokeAsync(() =>
            {
                OutputTextBox.Text += $"{ip} — active\n";
            });
        }
    }            
}