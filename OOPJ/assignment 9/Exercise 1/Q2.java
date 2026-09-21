import java.util.Comparator;

public class Q2 {
    public static void main(String[] args) {
        Integer[] arr = {10, 25, 7, 40, 15};

        Comparator<Integer> c = (a, b) -> a.compareTo(b);

        int largest = arr[0];

        for (int i = 1; i < arr.length; i++) {
            if (c.compare(largest, arr[i]) < 0) {
                largest = arr[i];
            }
        }

        System.out.println("Largest: " + largest);
    }
}