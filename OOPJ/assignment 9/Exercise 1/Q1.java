import java.util.Arrays;
import java.util.Comparator;

public class Q1 {
    public static void main(String[] args) {
        String[] arr = {"Mango", "Apple", "Orange", "Banana"};

        Arrays.sort(arr, (a, b) -> a.compareTo(b));

        for (String str : arr) {
            System.out.println(str);
        }
    }
}
