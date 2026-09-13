public class Triangle {

    int side1;
    int side2;
    int side3;

    public Triangle(int a, int b, int c) {
        side1 = a;
        side2 = b;
        side3 = c;
    }

    public int getPerimeter() {
        return side1 + side2 + side3;
    }

    public int getArea() {
        return (side1 * side2) / 2;
    }

    public static void main(String[] args) {

        Triangle t = new Triangle(3, 4, 5);

        System.out.println("Area: " + t.getArea());
        System.out.println("Perimeter: " + t.getPerimeter());
    }
}
