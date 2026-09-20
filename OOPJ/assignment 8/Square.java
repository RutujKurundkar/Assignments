package Rutuj;

public class Square implements RegularPolygon {
    private double sideLength;

    public Square(double sideLength) {
        this.sideLength = sideLength;
    }

    public int getNumSides() {
        return 4;
    }

    public double getSideLength() {
        return sideLength;
    }
}