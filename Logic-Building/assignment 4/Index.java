	import java.util.Scanner;
import java.util.Arrays;
class Index{
	public static void main (String[] args){
		Scanner sc = new Scanner (System.in);
		Integer arr[] = new Integer[5];
		System.out.println ("Enter 5 integers: ");
		for (int i=0; i<5; i++){
			arr[i] = sc.nextInt();
			}
		System.out.println ("Enter the number to search: ");
		int num = sc.nextInt();
		Arrays.sort (arr);
		int index = Arrays.binarySearch (arr, num);
		if (index >= 0){
			System.out.println ("The number " + num + " is found at index " + index);
		}
		else{
			System.out.println ("Not Found");
		}}}
