using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace task1_cs.Services;
public static class FileService
{
    public static List<char> ReadLettersFromFile(string path)
    {
        if (!File.Exists(path))
            return new List<char>();

        List<char> content = File.ReadAllText(path).ToList();
        return content;
    }
    
    public static void WriteLettersToFile(List<char> letters, string path)
    {
        string content = "";
        for (int i = 0; i < letters.Count(); i++)
        {
            content += letters[i];
            if ((i + 1) % 5 == 0)
                content += "\n";
            else
                content += " ";
        }
        File.WriteAllText(path, content);
    }
}