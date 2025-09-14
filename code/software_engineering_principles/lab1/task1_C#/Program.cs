using System;


class MyMath
{
    public string IsInTarget(double x, double y)
    {
        if (0 <= x && x <= Math.Sqrt(2) && 0 <= y && y <= 1)
        {
            if (y == x || y == -x * x + 2 || y == 0)
                return "На межі";
            else if (y < x && y < -x * x + 2)
                return "В області";
        }
        else if (-2 <= x && x <= 0 && -2 <= y && y <= 0)
        {
            if (y == x || y == -x * x + 2 || y == 0)
                return "На межі";
            else if (y > x && y < -x * x + 2)
                return "В області";
        }
        return "Не в області";
    }
}
class Program
{
    static void Main()
    {
        var mh = new MyMath();
        // На межі
        Console.WriteLine(mh.IsInTarget(-1, 0));
        Console.WriteLine(mh.IsInTarget(-2, -2));
        Console.WriteLine(mh.IsInTarget(1, 0));
        Console.WriteLine(mh.IsInTarget(1, 1));

        // В області
        Console.WriteLine(mh.IsInTarget(1, 0.5));

        // Не в області
        Console.WriteLine(mh.IsInTarget(0.5, 1));
        Console.WriteLine(mh.IsInTarget(-0.5, 0.5));
        Console.WriteLine(mh.IsInTarget(1, -0.5));

        while (true)
        {
            Console.WriteLine("Enter x and y: ");
            string[] parts = Console.ReadLine().Split(' ');
            double x = double.Parse(parts[0]);
            double y = double.Parse(parts[1]);
            string result = mh.IsInTarget(x, y);
            Console.WriteLine(result);
        }
    }
}