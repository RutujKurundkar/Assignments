package assignment5;

public class Q7 {
    public static void main(String[] args) {

        String str = "The quick brown fox jumps";

        System.out.println("The given string is: " + str);

        String str_1 = "";

        for (int i = str.length() - 1; i >= 0; i--) {
            str_1 = str_1 + str.charAt(i);
        }

        System.out.println("The string in reverse order is: " + str_1);
    }
}