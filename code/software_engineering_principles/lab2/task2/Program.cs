class Solver
{
    public static int[,] GenerateMatrix(int n, int minValue, int maxValue)
    {
        int[,] matrix = new int[n, n];
        Random rand = new Random();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                matrix[i, j] = rand.Next(minValue, maxValue + 1);
        return matrix;
    }

    public static int FindRowMax(int[,] matrix, int row)
    {
        int maxValue = matrix[row, 0];
        for (int j = 1; j < matrix.GetLength(1); j++)
            if (matrix[row, j] > maxValue)
                maxValue = matrix[row, j];
        return maxValue;
    }

    public static int[] BuildVector(int[,] matrix, int x)
    {
        int n = matrix.GetLength(0);
        int[] vector = new int[n];

        for (int i = 0; i < n; i++)
        {
            int rowMax = FindRowMax(matrix, i);
            vector[i] = (rowMax <= x) ? 0 : 1;
        }

        return vector;
    }

    public static void PrintMatrix(int[,] matrix)
    {
        for (int i = 0; i < matrix.GetLength(0); i++)
        {
            for (int j = 0; j < matrix.GetLength(1); j++)
                System.Console.Write($"{matrix[i, j],4}");
            System.Console.WriteLine();
        }
    }

    public static void PrintVector(int[] vector)
    {
        Console.WriteLine(string.Join(" ", vector));
    }
}

class Program
{
    static void Main()
    {
        int[,] A = Solver.GenerateMatrix(6, -50, 49);

        Console.Write("Enter x: ");
        int x = int.Parse(Console.ReadLine());

        int[] X = Solver.BuildVector(A, x);

        Console.WriteLine("\nМатриця A:");
        Solver.PrintMatrix(A);

        Console.WriteLine("\nВектор X:");
        Solver.PrintVector(X);
    }
}