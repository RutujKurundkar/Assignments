package Rutuj;

import java.util.TreeSet;

public class Q14 {
    public static void main(String[] args) {
        TreeSet<String> colors = new TreeSet<String>();

        colors.add("Red");
        colors.add("Green");
        colors.add("Blue");
        colors.add("Yellow");
        colors.add("Black");

        System.out.println("TreeSet: " + colors);
        System.out.println("First element: " + colors.first());
        System.out.println("Last element: " + colors.last());
    }
}