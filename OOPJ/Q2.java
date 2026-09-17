package assignment5;

public class Q2 {

	public static void main(String[] args) {
		String str = "This is Exercise 1";
		String str_2 = "This is Exercise 2";

		System.out.println ("String 1: " + str);
		System.out.println ("String 2: " + str_2);
		
		if ((str==str_2) && (str.length()==str_2.length()))
			System.out.println (str + "and" + str_2 + "are equal");
		else
			System.out.println ('"' + str + '"' + " is less than " + '"' + str_2 + '"');
	}

}
