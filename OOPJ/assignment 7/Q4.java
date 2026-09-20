package org.rutuj;

import java.util.ArrayList;

public class Q4 {
    public static void main(String[] args) {
        ArrayList<String> colors = new ArrayList<String>();

        colors.add("Red");
        colors.add("Green");
        colors.add("Blue");
        colors.add("Yellow");
        colors.add("Black");

        colors.set(2, "White");

        System.out.println(colors);
    }
}