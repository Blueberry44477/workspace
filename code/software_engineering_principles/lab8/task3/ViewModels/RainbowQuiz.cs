using task3.Models;
using System;
using System.Collections.Generic;

namespace task3.ViewModels;

public class RainbowQuiz
{
    private readonly Dictionary<RainbowColor, (string EnglishName, string Hex)> _colors =
        new()
        {
            { RainbowColor.Red, ("Red", "#FF0000") },
            { RainbowColor.Orange, ("Orange", "#FFA500") },
            { RainbowColor.Yellow, ("Yellow", "#FFFF00") },
            { RainbowColor.Green, ("Green", "#008000") },
            { RainbowColor.LightBlue, ("Light Blue", "#ADD8E6") },
            { RainbowColor.Blue, ("Blue", "#0000FF") },
            { RainbowColor.Violet, ("Violet", "#EE82EE") }
        };

    public string GetColorInfo(string input)
    {
        if (!Enum.TryParse<RainbowColor>(input, true, out var color))
            return "No Such Color.";

        switch (color)
        {
            case RainbowColor.Red:
            case RainbowColor.Orange:
            case RainbowColor.Yellow:
            case RainbowColor.Green:
            case RainbowColor.LightBlue:
            case RainbowColor.Blue:
            case RainbowColor.Violet:
                var info = _colors[color];
                return $"{color} — {info.EnglishName} ({info.Hex})";

            default:
                return "Unknown COlor.";
        }
    }
}