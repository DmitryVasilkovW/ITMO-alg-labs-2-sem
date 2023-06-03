
using System;

public class Program
{
    static bool isPerfectSquare(int n)
    {
        int sqrt_n = (int)Math.Sqrt(n);
        return (sqrt_n * sqrt_n == n);
    }

    public static void Main(string[] args)
    {
        int n = int.Parse(Console.ReadLine()); // чтение входных данных

        int count = 0;
        for (int a = 1; a <= n; a++)
        {
            for (int b = a + 1; b <= n; b++)
            {
                for (int c = b + 1; c <= n; c++)
                {
                    if (isPerfectSquare(a * b) && isPerfectSquare(a * c) && isPerfectSquare(b * c))
                    {
                        count++;
                    }
                }
            }
        }

        Console.WriteLine(count); // вывод результата
    }
}
