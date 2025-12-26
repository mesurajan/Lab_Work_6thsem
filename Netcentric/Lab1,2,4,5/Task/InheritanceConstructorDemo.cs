namespace Chapter1Console.Tasks;

public class Person
{
    public string Name { get; }
    public int Age { get; }

    // Base constructor
    public Person(string name, int age)
    {
        Name = name;
        Age = age;
    }

    public virtual string Describe() => $"{Name}, Age {Age}";
}

public class Student : Person
{
    public string RollNo { get; }
    public string Program { get; }

    // Derived constructor calls base(...)
    public Student(string name, int age, string rollNo, string program)
        : base(name, age)
    {
        RollNo = rollNo;
        Program = program;
    }

    public override string Describe() =>
        $"{base.Describe()}, Roll {RollNo}, Program {Program}";
}

public static class InheritanceConstructorDemo
{
    public static void Run()
    {
        Console.Write("Student name: ");
        string name = ReadNonEmpty();
        Console.Write("Age: ");
        int age = ReadInt();
        Console.Write("Roll No: ");
        string roll = ReadNonEmpty();
        Console.Write("Program (e.g., BSc CSIT): ");
        string prog = ReadNonEmpty();

        var s = new Student(name, age, roll, prog);
        Console.WriteLine("\nCreated object:");
        Console.WriteLine(s.Describe());
    }

    static string ReadNonEmpty()
    {
        while (true)
        {
            var s = Console.ReadLine();
            if (!string.IsNullOrWhiteSpace(s)) return s.Trim();
            Console.Write("Please enter a value: ");
        }
    }

    static int ReadInt()
    {
        while (true)
        {
            var s = Console.ReadLine();
            if (int.TryParse(s, out int x) && x >= 0) return x;
            Console.Write("Enter a valid non-negative integer: ");
        }
    }
}
