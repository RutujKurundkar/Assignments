package assignment5;

public class Q5 {

	public static void main(String[] args) {
		String str =  "The quick brown fox jumps over the lazy dog.";
		String str_2 = str.replaceAll("fox", "cat");
		System.out.println ("Original string: " + str);
		System.out.println ("New String: " + str_2);
	}

}
