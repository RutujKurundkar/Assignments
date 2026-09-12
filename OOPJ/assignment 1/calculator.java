public class calculator {

	public static void main(String[] args) {
		System.out.println ("Enter your choice: ");
		int choice = ConsoleInput.getInt();
		
		System.out.println ("Enter first number: ");
		int num1 = ConsoleInput.getInt();
		
		System.out.println ("Enter second number: ");
		int num2 = ConsoleInput.getInt();

		System.out.println ("Enter third number: ");
		int num3 = ConsoleInput.getInt();
  
	/*switch (choice) {
	case 1:
		System.out.println ("Sum: " + (num1 + num2));
	break;
	case 2:
		System.out.println ("Difference: " + (num1 - num2));
	break;
	case 3:
		System.out.println ("Product: " + (num1 * num2));
	break;
	case 4:
		System.out.println ("Division: " + (num1 / num2));
	break;
	case 5:
		System.out.println ("Remainder: " + (num1 % num2));
	break;
	default:
		System.out.println ("Incorrect operation");
}*/
	
	switch (choice) {
	case 1:
		System.out.println ("Sum: " + calculate(num1, num2));
	break;
	case 2:
		System.out.println ("Sum: " + calculate(num1, num2, num3));
	break;
	default:
		System.out.println ("Incorrect choice");
}}
	
	//Overloading:-
		static int calculate (int a, int b) {
			System.out.println ("Case 1 output: ");
			return a+b;
		}
		static int calculate (int a, int b, int c) {
			System.out.println ("Case 2 output: ");
			return a+b+c;
}}