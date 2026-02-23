using System.Collections.Generic;
namespace task2_cs.Models;
public class DirectedGraph
{
    public int VertexCount { get; }
    public List<(int u, int v)> Edges { get; }

    public DirectedGraph(int vertexCount, List<(int u, int v)> edges)
    {
        VertexCount = vertexCount;
        Edges = edges;
    }

    public int[,] GetAdjacencyMatrix()
    {
        var matrix = new int[VertexCount, VertexCount];

        foreach (var edge in Edges)
            matrix[edge.u, edge.v] = 1; 

        return matrix;
    }

    public int[,] GetIncidenceMatrix()
    {
        var m = new int[VertexCount, Edges.Count];

        for (int i = 0; i < Edges.Count; i++)
        {
            var (u, v) = Edges[i];
            m[u, i] = -1;
            m[v, i] = 1;
        }

        return m;
    }
}
