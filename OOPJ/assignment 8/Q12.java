package Rutuj;

import java.util.TreeSet;

public class Q12 {
    public static void main(String[] args) {
        TreeSet<String> colors = new TreeSet<String>();

        colors.add("Red");
        colors.add("Green");
        colors.add("Blue");
        colors.add("Yellow");
        colors.add("Black");

        TreeSet<String> newColors = new TreeSet<String>();

        newColors.add("White");
        newColors.add("Orange");

        newColors.addAll(colors);

        System.out.println("First TreeSet: " + colors);
        System.out.println("Second TreeSet: " + newColors);
    }
}