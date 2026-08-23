import java.util.Scanner;
class Count{
	public static void main (String[] args){
		Scanner sc = new Scanner (System.in);
		int arr[] = new int[6];
		int positive=0;
		int negative=0;
		System.out.println ("Enter 6 integers: ");
		for (int i=0; i<6; i++){
			arr[i] = sc.nextInt();
			if (arr[i]>0){
				positive++;
			}
			else if (arr[i]<0){
				negative++;
			}}
			System.out.println ("Positive numbers: " + positive);
			System.out.println ("Negative numbers: " + negative);
}}