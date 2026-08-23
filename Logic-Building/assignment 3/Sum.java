//Using method:-
import java.util.Scanner;
class Sum{
	static int sumOfTwoNumbers (int a, int b){
		return a+b;
}
	public static void main (String[] args){
		Scanner sc = new Scanner (System.in);
		System.out.println ("Enter first number: ");
		int num_1 = sc.nextInt();
		System.out.println ("Enter second number: ");
		int num_2 = sc.nextInt();
		int add = sumOfTwoNumbers (num_1, num_2);
		System.out.println ("The sum of " + num_1 + " and " + num_2 + " is " + add + ".");
}}

/*//Without using method:-
import java.util.Scanner;
class Sum{
	public static void main (String args[]){
		Scanner sc = new Scanner (System.in);
		System.out.println ("Enter first number: ");
		int num_1 = sc.nextInt();
		System.out.println ("Enter second number: ");
		int num_2 = sc.nextInt();
		int add = num_1 + num_2;
		System.out.println ("The sum of " + num_1 + " and " + num_2 + " is " + add + ".");
}}*/