using System.Collections;
using System.Collections.Generic;

namespace task3.Models;

// IEnumerable implementation
public class PlaneCollection : IEnumerable<Plane>
{
    private readonly List<Plane> _planes = new();

    public void Add(Plane plane) => _planes.Add(plane);

    public IEnumerator<Plane> GetEnumerator() => _planes.GetEnumerator();

    IEnumerator IEnumerable.GetEnumerator() => GetEnumerator();

    public Plane[] ToArray() => _planes.ToArray();
}
