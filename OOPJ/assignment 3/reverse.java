public class reverse {

    public static void main(String[] args) {

        System.out.println("Enter the size of array:");
        int size = ConsoleInput.getInt();

        int[] arr = new int[size];
        int[] reverse = new int[size];

        for (int i = 0; i < size; i++) {
            System.out.println("Enter element " + (i + 1) + ":");
            arr[i] = ConsoleInput.getInt();
        }

        for (int i = 0; i < size; i++) {
            reverse[i] = arr[size - 1 - i];
        }

        System.out.print("Original array: ");

        for (int i = 0; i < size; i++) {
            System.out.print(arr[i] + " ");
        }

        System.out.println();

        System.out.print("Reversed array: ");

        for (int i = 0; i < size; i++) {
            System.out.print(reverse[i] + " ");
        }
    }
}