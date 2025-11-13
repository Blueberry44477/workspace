using System.Collections.Generic;
using task1_cs.Models;
using task1_cs.Services;
namespace task1_cs.ViewModels;

public partial class MainWindowViewModel : ViewModelBase
{
    public string? InputFilePath { get; set; }
    public string? OutputFilePath { get; set; }

    public List<char> List1 { get; set; } = new List<char>();
    public List<char> List2 { get; set; } = new List<char>();

    public void LoadFile()
    {
        List1 = FileService.ReadLettersFromFile(InputFilePath);
    }

    public void ProcessLetters()
    {
        List2 = LetterProcessor.CreateList2(List1);
    }

    public void SaveFile()
    {
        FileService.WriteLettersToFile(List2, OutputFilePath);
    }
}
