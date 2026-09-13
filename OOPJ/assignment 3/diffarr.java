public class diffarr {

    public static void main(String[] args) {

        System.out.println("Enter size of first array:");
        int size1 = ConsoleInput.getInt();

        int[] arr1 = new int[size1];

        for (int i = 0; i < size1; i++) {
            System.out.println("Enter element " + (i + 1) + " of first array:");
            arr1[i] = ConsoleInput.getInt();
        }

        System.out.println("Enter size of second array:");
        int size2 = ConsoleInput.getInt();

        int[] arr2 = new int[size2];

        for (int i = 0; i < size2; i++) {
            System.out.println("Enter element " + (i + 1) + " of second array:");
            arr2[i] = ConsoleInput.getInt();
        }

        System.out.print("Common elements: ");

        for (int i = 0; i < size1; i++) {
            for (int j = 0; j < size2; j++) {

                if (arr1[i] == arr2[j]) {
                    System.out.print(arr1[i] + " ");
                    break;
                }
            }
        }
    }
}