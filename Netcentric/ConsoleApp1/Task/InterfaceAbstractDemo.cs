namespace Chapter1Console.Tasks;

// Interface
public interface IShape
{
    double Area();
}

// Abstract class implementing the interface
public abstract class Shape : IShape
{
    public string Name { get; }
    protected Shape(string name) => Name = name;
    public abstract double Area();
    public override string ToString() => $"{Name} : Area = {Area():0.###}";
}

// Concrete classes
public class Rectangle : Shape
{
    public double Width { get; }
    public double Height { get; }
    public Rectangle(double width, double height) : base("Rectangle")
    {
        Width = width; Height = height;
    }
    public override double Area() => Width * Height;
}

public class Circle : Shape
{
    public double Radius { get; }
    public Circle(double radius) : base("Circle") => Radius = radius;
    public override double Area() => Math.PI * Radius * Radius;
}

public static class InterfaceAbstractDemo
{
    public static void Run()
    {
        Console.Write("Enter rectangle width: ");
        double w = ReadPositive();
        Console.Write("Enter rectangle height: ");
        double h = ReadPositive();
        var rect = new Rectangle(w, h);

        Console.Write("Enter circle radius: ");
        double r = ReadPositive();
        var circle = new Circle(r);

        var shapes = new List<IShape> { rect, circle };

        Console.WriteLine("\nComputed Areas:");
        foreach (var s in shapes) Console.WriteLine(s);
    }

    private static double ReadPositive()
    {
        while (true)
        {
            var s = Console.ReadLine();
            if (double.TryParse(s, out double x) && x > 0) return x;
            Console.Write("Enter a positive number: ");
        }
    }
}
