package Rutuj;

import java.util.ArrayList;
import java.util.Collections;

public class Q9 {
    public static void main(String[] args) {
        ArrayList<String> colors = new ArrayList<String>();

        colors.add("Red");
        colors.add("Green");
        colors.add("Blue");
        colors.add("Yellow");
        colors.add("Black");

        System.out.println("Before shuffling: " + colors);

        Collections.shuffle(colors);

        System.out.println("After shuffling: " + colors);
    }
}