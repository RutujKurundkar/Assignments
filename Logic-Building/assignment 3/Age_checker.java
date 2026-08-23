//Using method:-
import java.util.Scanner;
class Age_checker{
	static int checkAgeCategory (int age){
	if (age<18){
		System.out.println ("You are a minor.");
	}
	else if (age>=18 && age<=59){
		System.out.println ("You are an adult.");
	}
	else{
		System.out.println ("You are a senior citizen.");
	}
	return age;
}
public static void main (String[] args){
	Scanner sc = new Scanner (System.in);
	System.out.println ("Enter your age: ");
	int age = sc.nextInt();
	checkAgeCategory (age);
}}

/*//Without using method:-
import java.util.Scanner;
class Age_checker{
	public static void main (String[] args){
		Scanner sc = new Scanner (System.in);
		System.out.println ("Enter your age: ");
		int age = sc.nextInt();
		if (age<18){
		System.out.println ("You are a minor.");
	}
	else if (age>=18 && age<=59){
		System.out.println ("You are an adult.");
	}
	else{
		System.out.println ("You are a senior citizen.");
	}
	}
}*/