import java.util.Scanner;
class Odd{
	public static void main (String[] args){
		Scanner sc = new Scanner (System.in);
		System.out.println ("Enter a number: ");
		int N = sc.nextInt();
		int sum=0;
		for (int i=1; i<=N; i++){
			if (i%2 != 0){
				sum = sum + i;
}}
	System.out.println ("The sum of odd numbers from 1 to " + N + " is: " + sum);
}}