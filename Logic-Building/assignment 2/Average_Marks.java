class Average_Marks{
	public static void main (String args[]){
		int marks_Maths = 80;
		int marks_Science = 85;
		int marks_History = 90;

		/*int marks_Maths = 70;
		int marks_Science = 75;
		int marks_History = 70;*/
		double Average_Marks = (marks_Maths + marks_Science + marks_History)/3; 
		System.out.println ("Average Marks: " + Average_Marks);
		if (Average_Marks >= 90){
			System.out.println ("Grade: A");
		}
		else if (Average_Marks >= 70 && Average_Marks <= 89){
			System.out.println ("Grade: B");
		}
		else if (Average_Marks >= 50 && Average_Marks <= 69){
			System.out.println ("Grade: C");
		}
		else if (Average_Marks >= 30 && Average_Marks <= 49){
			System.out.println ("Grade: D");
		}
		else{
			System.out.println ("Fail");
		}}}