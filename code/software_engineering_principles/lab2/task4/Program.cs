using System;

class Program
{
    static void Main()
    {
        Console.Write("Enter rows count (n): ");
        int n = int.Parse(Console.ReadLine());

        int[][] jaggedArray = new int[n][];

        Random rnd = new Random();

        for (int i = 0; i < n; i++)
        {
            Console.Write($"Enter number of row {i} elements: ");
            int m = int.Parse(Console.ReadLine());

            jaggedArray[i] = new int[m];
            for (int j = 0; j < m; j++)
                jaggedArray[i][j] = rnd.Next(1, 10);
        }

        Console.Write("Enter vector X size: ");
        int sizeX = int.Parse(Console.ReadLine());
        int[] X = new int[sizeX];

        Console.WriteLine("Введіть елементи вектора X:");
        for (int i = 0; i < sizeX; i++)
            X[i] = int.Parse(Console.ReadLine());

        for (int i = 1; i < n; i += 2)
            jaggedArray[i] = (int[])X.Clone(); 

        Console.WriteLine();
        for (int i = 0; i < n; i++)
        {
            Console.WriteLine(string.Join(" ", jaggedArray[i]));
        }
    }
}
