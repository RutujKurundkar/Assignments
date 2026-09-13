class Rectangle {

    private double length;
    private double breadth;

    public Rectangle(double length, double breadth) {
        this.length = length;
        this.breadth = breadth;
    }

    public void printArea() {
        System.out.println("Area: " + (length * breadth));
    }

    public void printPerimeter() {
        System.out.println("Perimeter: " + (2 * (length + breadth)));
    }
}

class Square extends Rectangle {

    public Square(double side) {
        super(side, side);
    }
}

public class RectangleDemo {

    public static void main(String[] args) {

        System.out.print("Enter length of rectangle: ");
        double length = ConsoleInput.getDouble();

        System.out.print("Enter breadth of rectangle: ");
        double breadth = ConsoleInput.getDouble();

        Rectangle r = new Rectangle(length, breadth);

        System.out.println("\nRectangle:");
        r.printArea();
        r.printPerimeter();

        System.out.print("\nEnter side of square: ");
        double side = ConsoleInput.getDouble();

        Square s = new Square(side);

        System.out.println("\nSquare:");
        s.printArea();
        s.printPerimeter();
    }
}
