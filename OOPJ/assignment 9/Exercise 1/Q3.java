import java.util.Comparator;

public class Q3 {
    public static void main(String[] args) {
        Integer[] arr = {10, 25, 7, 40, 15};

        Comparator<Integer> c = (a, b) -> a.compareTo(b);

        int smallest = arr[0];

        for (int i = 1; i < arr.length; i++) {
            if (c.compare(smallest, arr[i]) > 0) {
                smallest = arr[i];
            }
        }

        System.out.println("Smallest: " + smallest);
    }
}