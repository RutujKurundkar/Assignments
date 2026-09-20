package Rutuj;

public interface RegularPolygon {
    int getNumSides();
    double getSideLength();

    static int totalSides(RegularPolygon[] polygons) {
        int total = 0;

        for (RegularPolygon polygon : polygons) {
            total += polygon.getNumSides();
        }

        return total;
    }

    default double getPerimeter() {
        return getNumSides() * getSideLength();
    }

    default double getInteriorAngle() {
        int n = getNumSides();
        return (n - 2) * Math.PI / n;
    }
}
