public class Average {

    public static void main(String[] args) {

        System.out.println("Enter the size of array:");
        int size = ConsoleInput.getInt();

        int[] arr = new int[size];
        int sum = 0;

        for (int i = 0; i < size; i++) {
            System.out.println("Enter element " + (i + 1) + ":");
            arr[i] = ConsoleInput.getInt();
            sum = sum + arr[i];
        }

        double average = (double) sum / size;

        System.out.println("Average of array elements: " + average);
    }
}