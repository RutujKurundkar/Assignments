import java.util.Scanner;
class Even{
	public static void main (String[] args){
	Scanner sc = new Scanner (System.in);
	System.out.println ("Enter a number: ");
	int N = sc.nextInt();
	for (int i=1; i<=N; i++){
		if (i%2 == 0){
			System.out.print (i + " ");
}}}}
