using System;

namespace Calculator
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Enter expression to calculate: ");
            string buf = Console.ReadLine();

            Expression expr = new Expression(buf);
            Console.WriteLine($"\nResult = {expr.Calculate()}");

            Console.ReadKey();
        }
    }
}
