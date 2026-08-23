import java.util.Scanner;
class Factorial{
	public static void main (String[] args){
	Scanner sc = new Scanner (System.in);
	System.out.println ("Enter a number: ");
	int N = sc.nextInt();
	int num=1;
	for (int i=1; i<=N; i++){
		num = num*i;
	}
		System.out.println ("Factorial of " + N + " is " + num);
}}