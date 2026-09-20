package Rutuj;

import java.util.ArrayList;
import java.util.Collections;

public class Q8 {
    public static void main(String[] args) {
        ArrayList<String> colors = new ArrayList<String>();

        colors.add("Red");
        colors.add("Green");
        colors.add("Blue");
        colors.add("Yellow");
        colors.add("Black");

        ArrayList<String> newColors = new ArrayList<String>();

        for (int i = 0; i < colors.size(); i++) {
            newColors.add("");
        }

        Collections.copy(newColors, colors);

        System.out.println("Original ArrayList: " + colors);
        System.out.println("Copied ArrayList: " + newColors);
    }
}
