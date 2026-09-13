
public class Array {
	
	public static void main(String[] args) {
		System.out.println ("Enter the size of array:");
		int size = ConsoleInput.getInt();
		int[] arr = new int[size];
		for (int i=0; i<size; i++) {
			System.out.println ("Enter element: " + (i+1) + ":");
			arr[i] = ConsoleInput.getInt();
		}
		
		for (int i=0; i<size; i++) {
			for (int j=i+1; j<size; j++) {
				if (arr[i] > arr[j]) {
					int temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
		}}}
		
		System.out.println ("Sorted Array: ");
		
		for (int i=0; i<size; i++) {
			System.out.print (arr[i] + " ");
}}}
