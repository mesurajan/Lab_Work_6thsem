namespace Chapter1Console.Tasks;

public static class SumTwoNumbers
{
    public static void Run()
    {
        Console.Write("Enter first number: ");
        var a = ReadDouble();
        Console.Write("Enter second number: ");
        var b = ReadDouble();

        Console.WriteLine($"Sum = {a + b}");
    }

    private static double ReadDouble()
    {
        while (true)
        {
            var s = Console.ReadLine();
            if (double.TryParse(s, out double x)) return x;
            Console.Write("Invalid number, try again: ");
        }
    }
}
