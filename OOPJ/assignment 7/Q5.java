package org.rutuj;

import java.util.ArrayList;

public class Q5 {
    public static void main(String[] args) {
        ArrayList<String> colors = new ArrayList<String>();

        colors.add("Red");
        colors.add("Green");
        colors.add("Blue");
        colors.add("Yellow");
        colors.add("Black");

        colors.remove(2);

        System.out.println(colors);
    }
}