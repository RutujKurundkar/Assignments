import java.util.function.UnaryOperator;

public class Q5{
    public static void main(String[] args) {
        UnaryOperator<int[]> reverse = arr -> {
            int[] rev = new int[arr.length];

            for (int i = 0; i < arr.length; i++) {
                rev[i] = arr[arr.length - 1 - i];
            }

            return rev;
        };

        int[] arr = {10, 20, 30, 40, 50};

        int[] result = reverse.apply(arr);

        for (int i : result) {
            System.out.println(i);
        }
    }
}