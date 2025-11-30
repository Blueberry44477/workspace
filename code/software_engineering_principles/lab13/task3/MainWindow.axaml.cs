using Avalonia.Controls;
using Avalonia.Interactivity;
using Microsoft.Recognizers.Text;
using Microsoft.Recognizers.Text.Sequence;
using Microsoft.Recognizers.Text.DateTime;
using Microsoft.Recognizers.Text.NumberWithUnit;
using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;

namespace task3;

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
        }
    }

    private void RecognizeButton_Click(object? sender, RoutedEventArgs e)
    {

        string input = InputTextBox.Text ?? "";
        OutputTextBox.Text = "";

        var result = new Dictionary<string, List<ModelResult>>();

        result["Currency"] = NumberWithUnitRecognizer.RecognizeCurrency(input, Culture.English);
        result["Dimension"] = NumberWithUnitRecognizer.RecognizeDimension(input, Culture.English);
        result["Temperature"] = NumberWithUnitRecognizer.RecognizeTemperature(input, Culture.English);

        result["DateTime"] = DateTimeRecognizer.RecognizeDateTime(input, Culture.English);

        result["Phone"] = SequenceRecognizer.RecognizePhoneNumber(input, Culture.English);
        result["IP"] = SequenceRecognizer.RecognizeIpAddress(input, Culture.English);
        result["Email"] = SequenceRecognizer.RecognizeEmail(input, Culture.English);
        result["URL"] = SequenceRecognizer.RecognizeURL(input, Culture.English);
        result["Hashtag"] = SequenceRecognizer.RecognizeHashtag(input, Culture.English);

        Dictionary<string, int> stats = result.ToDictionary(pair => pair.Key, pair => pair.Value.Count);

        // Update OutputBox.Text
        foreach (var pair in result)
        {
            string groupName = pair.Key;
            List<ModelResult> items = pair.Value;

            foreach (var item in items)
            {
                OutputTextBox.Text += $"{groupName}: {item.Text} [{item.Start}; {item.End}]\n";
            }
        }
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