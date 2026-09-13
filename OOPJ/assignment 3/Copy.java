public class Copy {

    public static void main(String[] args) {

        System.out.println("Enter the size of array:");
        int size = ConsoleInput.getInt();

        int[] arr1 = new int[size];
        int[] arr2 = new int[size];

        for (int i = 0; i < size; i++) {
            System.out.println("Enter element " + (i + 1) + ":");
            arr1[i] = ConsoleInput.getInt();
        }
        
        System.out.print ("Original array: ");
        for (int i = 0; i < size; i++) {
        	System.out.print (arr1[i] + " ");
        }
        
        for (int i = 0; i < size; i++) {
            arr2[i] = arr1[i];
        }
        System.out.println();

        System.out.print ("Copied array: ");

        for (int i = 0; i < size; i++) {
            System.out.print (arr2[i] + " ");
        }
    }
}