public class max {

    public static void main(String[] args) {

        System.out.println("Enter the size of array:");
        int size = ConsoleInput.getInt();

        int[] arr = new int[size];

        for (int i = 0; i < size; i++) {
            System.out.println("Enter element " + (i + 1) + ":");
            arr[i] = ConsoleInput.getInt();
        }

        int max = arr[0];
        int min = arr[0];

        for (int i = 1; i < size; i++) {

            if (arr[i] > max) {
                max = arr[i];
            }

            if (arr[i] < min) {
                min = arr[i];
            }
        }

        System.out.println("Maximum value: " + max);
        System.out.println("Minimum value: " + min);
    }
}