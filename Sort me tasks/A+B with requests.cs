using System;

public class Program
{
    public static void Main()
    {
        int t = int.Parse(Console.ReadLine()); 

        for (int i = 0; i < t; i++)
        {
            string[] input = Console.ReadLine().Split(); 
            int a = int.Parse(input[0]);
            int b = int.Parse(input[1]);

            int sum = a + b;

            Console.WriteLine(sum);
        }
    }
}
