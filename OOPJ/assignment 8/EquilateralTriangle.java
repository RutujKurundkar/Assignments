package Rutuj;

public class EquilateralTriangle implements RegularPolygon {
    private double sideLength;

    public EquilateralTriangle(double sideLength) {
        this.sideLength = sideLength;
    }

    public int getNumSides() {
        return 3;
    }

    public double getSideLength() {
        return sideLength;
    }
}