class Leapyear{
	public static void main (String[] args){
		int year_1 = 2024;
		int year_2 = 1900;
		int year_3 = 2004;
		if (year_1 % 4 == 0 && year_1 % 100 != 0 || year_1 % 400 == 0){
			System.out.println (year_1 + " is a leap year");
		}
		else{
			System.out.println (year_1 + " is not a leap year");
		}
		if (year_2 % 4 == 0 && year_2 % 100 != 0 || year_2 % 400 == 0){
			System.out.println (year_2 + " is a leap year");
		}
		else{
			System.out.println (year_2 + " is not a leap year");
		}
		if (year_3 % 4 == 0 && year_3 % 100 != 0 || year_3 % 400 == 0){
			System.out.println (year_3 + " is a leap year");
		}
		else{
			System.out.println (year_3 + " is not a leap year");
		}
		
}}