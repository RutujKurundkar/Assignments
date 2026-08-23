import java.util.Scanner;
import java.util.Arrays;
class Check{
	public static void main (String[] args){
	Scanner sc = new Scanner (System.in);
	Integer arr[] = new Integer[5];
	System.out.println ("Enter 5 integers: ");
	for (int i=0; i<5; i++){
		arr[i] = sc.nextInt();
		}
		System.out.println ("Enter the number to search: ");
		int num = sc.nextInt();
		if (Arrays.asList (arr).contains (num)){
			System.out.println ("Found");
		}
		else{
			System.out.println ("Not Found");
}}}