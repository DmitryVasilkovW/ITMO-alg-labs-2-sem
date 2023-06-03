using System;

class Program {
    static void Main(){
        string[] input = Console.ReadLine().Split();
        int a = int.Parse(input[0]);
        int b = int.Parse(input[1]);
        int sum = a + b;
        Console.WriteLine(sum);
    }
}
