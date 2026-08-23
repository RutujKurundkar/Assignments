import java.util.Scanner;
class Average{
    public static void main (String[] args){
        Scanner sc = new Scanner (System.in);
        int[] numbers = new int[5];
        int sum = 0;
        System.out.println ("Enter 5 integers: ");
        for (int i=0; i<5; i++){
            numbers[i] = sc.nextInt();
            sum = sum + numbers[i];
        }
        float average = sum / 5.0f;
        System.out.println ("The average of the numbers is: " + average);
    }}