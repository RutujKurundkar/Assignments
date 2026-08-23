//Using method:-
import java.util.Scanner;
class Newsum{
	static void calculateSum (int N){
		if (N>0){
			int sum=0;
			for (int i=1; i<=N; i++){
				sum = sum+i;
	}
	System.out.println ("The sum of numbers from 1 to 5 is: " + sum);
	}
		else{
	System.out.println ("Invalid number");
		}}
public static void main (String[] args){
	Scanner sc = new Scanner (System.in);
	System.out.println ("Enter a number: ");
	int N = sc.nextInt();
	calculateSum (N);
}}

/*//Without using method:-
import java.util.Scanner;
public static void main (String[] args){
	Scanner sc = new Scanner (System.in);
	System.out.println ("Enter a number: ");
	int N = sc.nextInt();
	if (N>0){
			int sum=0;
			for (int i=1; i<=N; i++){
				sum = sum+i;
	}
	System.out.println ("The sum of numbers from 1 to 5 is: " + sum);
	}
		else{
	System.out.println ("Invalid number");
}}*/