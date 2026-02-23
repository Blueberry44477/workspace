using System;
using System.Linq;
using System.Collections.Generic;
using Avalonia.Controls;
using task2_cs.Models;

namespace task2_cs;

public partial class MainWindow : Window
{
private DirectedGraph? graph;

    public MainWindow()
    {
        InitializeComponent();

        BuildBtn.Click += BuildGraph;
        AdjBtn.Click += ShowAdjacency;
        IncBtn.Click += ShowIncidence;
    }

    private void BuildGraph(object? sender, Avalonia.Interactivity.RoutedEventArgs e)
    {
        int v = int.Parse(VerticesBox.Text!.Trim());

        var edges = EdgesBox.Text!
            .Split(',', StringSplitOptions.RemoveEmptyEntries)
            .Select(e => e.Split('>'))
            .Select(p => (int.Parse(p[0]), int.Parse(p[1])))
            .ToList();

        graph = new DirectedGraph(v, edges);
        Output.Text = "Built.";
    }

    private void ShowAdjacency(object? sender, Avalonia.Interactivity.RoutedEventArgs e)
    {
        if (graph == null)
        {
            Output.Text = "Build Graph First.";
            return;
        }

        var m = graph.GetAdjacencyMatrix();
        Output.Text = MatrixToString(m);
    }

    private void ShowIncidence(object? sender, Avalonia.Interactivity.RoutedEventArgs e)
    {
        if (graph == null)
        {
            Output.Text = "Build Graph First.";
            return;
        }

        var m = graph.GetIncidenceMatrix();
        Output.Text = MatrixToString(m);
    }

    private string MatrixToString(int[,] m)
    {
        int rows = m.GetLength(0);
        int cols = m.GetLength(1);

        var lines = new List<string>();

        for (int i = 0; i < rows; i++)
        {
            string line = "";
            for (int j = 0; j < cols; j++)
                line += m[i, j] + " ";

            lines.Add(line);
        }

        return string.Join('\n', lines);
    }
}