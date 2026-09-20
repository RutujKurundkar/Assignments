package Rutuj;

public class Main {
    public static void main(String[] args) {
        RegularPolygon[] polygons = {
            new EquilateralTriangle(5),
            new Square(4)
        };

        System.out.println("Total sides: " + RegularPolygon.totalSides(polygons));

        System.out.println("Triangle sides: " + polygons[0].getNumSides());
        System.out.println("Triangle side length: " + polygons[0].getSideLength());
        System.out.println("Triangle perimeter: " + polygons[0].getPerimeter());
        System.out.println("Triangle interior angle: " + polygons[0].getInteriorAngle());

        System.out.println("Square sides: " + polygons[1].getNumSides());
        System.out.println("Square side length: " + polygons[1].getSideLength());
        System.out.println("Square perimeter: " + polygons[1].getPerimeter());
        System.out.println("Square interior angle: " + polygons[1].getInteriorAngle());
    }
}