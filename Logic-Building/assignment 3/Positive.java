//Using method:-
import java.util.Scanner;
class Positive{	
	static int askForPositiveNumber (int num){
	Scanner sc = new Scanner (System.in);
	do{
		System.out.println ("Enter a number: ");
		num = sc.nextInt();
		}
		while (num<=0);
	return num;
}
public static void main (String[] args){
	int num = 0;
	num = askForPositiveNumber (num);
	System.out.println ("You entered a positive number: " + num);
}}

/*//Without using method:-
import java.util.Scanner;
class Positive{
	public static void main (String[] args){
		Scanner sc = new Scanner (System.in);
		int num;
	do{
		System.out.println ("Enter a number: ");
		num = sc.nextInt();
		}
		while (num<=0);
	System.out.println ("You entered a positive number: " + num);
	sc.close();
	}
}*/
		
		
		
	
