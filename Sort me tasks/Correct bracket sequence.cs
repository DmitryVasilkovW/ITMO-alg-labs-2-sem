using System;
using System.Collections.Generic;

public class Program
{
    public static void Main()
    {
        string s = Console.ReadLine();
        Stack<char> stack = new Stack<char>();
        foreach (char c in s)
        {
            if (c == '(')
            {
                stack.Push(c);
            }
            else if (c == ')')
            {
                if (stack.Count == 0 || stack.Peek() != '(')
                {
                    Console.WriteLine("NO");
                    return;
                }
                stack.Pop();
            }
        }
        if (stack.Count == 0)
        {
            Console.WriteLine("YES");
        }
        else
        {
            Console.WriteLine("NO");
        }
    }
} 
