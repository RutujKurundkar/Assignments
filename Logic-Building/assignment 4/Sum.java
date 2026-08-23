import java.util.Scanner;
class Sum{
	public static void main (String[] args){
		Scanner sc = new Scanner (System.in);
		int arr[] = new int[5];
		System.out.println ("Enter 5 integers: ");
		for (int i=0; i<5; i++){
			arr[i] = sc.nextInt();
		}
		int sum=0;
	for (int num: arr){	
		sum = sum + num;
}
	System.out.print ("The sum of all numbers is: " + sum);
}}