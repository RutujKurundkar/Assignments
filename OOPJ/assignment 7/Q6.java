package org.rutuj;

import java.util.ArrayList;

public class Q6 {
    public static void main(String[] args) {
        ArrayList<String> colors = new ArrayList<String>();

        colors.add("Red");
        colors.add("Green");
        colors.add("Blue");
        colors.add("Yellow");
        colors.add("Black");

        if (colors.contains("Blue")) {
            System.out.println("Element found");
        } else {
            System.out.println("Element not found");
        }
    }
}
