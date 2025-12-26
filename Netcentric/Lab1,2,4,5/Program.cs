using Chapter1Console.Tasks;

Console.OutputEncoding = System.Text.Encoding.UTF8;

while (true)
{
    Console.WriteLine("=== Chapter-1 Tasks ===");
    Console.WriteLine("1) Read two numbers and display sum");
    Console.WriteLine("2) Interface + Abstract class demo");
    Console.WriteLine("3) Inheritance + Constructors demo");
    Console.WriteLine("0) Exit");
    Console.Write("Enter choice: ");
    var input = Console.ReadLine();
    Console.WriteLine();

    switch (input)
    {
        case "1":
            SumTwoNumbers.Run();
            break;
        case "2":
            InterfaceAbstractDemo.Run();
            break;
        case "3":
            InheritanceConstructorDemo.Run();
            break;
        case "0":
            return;
        default:
            Console.WriteLine("Invalid choice. Try 0-3.");
            break;
    }

    Console.WriteLine();
}
