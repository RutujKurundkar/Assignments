//Using method:-
import java.util.Scanner;
class Bonus {
    // Instance variables
    byte a;
    short b;
    int c;
    long d;
    float e;
    double f;
    char g;
    boolean h;
    // Method for Problem 1
    static void gradeEvaluation() {
        int marks_Maths = 80;
        int marks_Science = 85;
        int marks_History = 90;
        double Average_Marks =
            (marks_Maths + marks_Science + marks_History) / 3.0;
        System.out.println("Average Marks: " + Average_Marks);
        if (Average_Marks >= 90) {
            System.out.println("Grade: A");
        }
        else if (Average_Marks >= 70) {
            System.out.println("Grade: B");
        }
        else if (Average_Marks >= 50) {
            System.out.println("Grade: C");
        }
        else if (Average_Marks >= 30) {
            System.out.println("Grade: D");
        }
        else {
            System.out.println("Fail");
        }
    }
    // Method for Problem 2
    static void leapYearCheck() {
        int year = 2024;
        if ((year % 4 == 0 && year % 100 != 0) ||
            year % 400 == 0) {
            System.out.println(year + " is a leap year");
        }
        else {
            System.out.println(year + " is not a leap year");
        }
    }
    // Method for Problem 3
    static void dayOfWeek(Scanner sc) {
        System.out.println("Enter the number: ");
        int day = sc.nextInt();
        switch (day) {
            case 1:
                System.out.println("The day is Monday.");
                break;
            case 2:
                System.out.println("The day is Tuesday.");
                break;
            case 3:
                System.out.println("The day is Wednesday.");
                break;
            case 4:
                System.out.println("The day is Thursday.");
                break;
            case 5:
                System.out.println("The day is Friday.");
                break;
            case 6:
                System.out.println("The day is Saturday.");
                break;
            case 7:
                System.out.println("The day is Sunday.");
                break;
            default:
                System.out.println("Invalid day");
        }
    }
    // Method for Problem 4
    static void defaultValues(Bonus obj) {
        System.out.println("Default value of byte: " + obj.a);
        System.out.println("Default value of short: " + obj.b);
        System.out.println("Default value of int: " + obj.c);
        System.out.println("Default value of long: " + obj.d);
        System.out.println("Default value of float: " + obj.e);
        System.out.println("Default value of double: " + obj.f);
        System.out.println("Default value of char: " + (int)obj.g);
        System.out.println("Default value of boolean: " + obj.h);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int choice = 0;
        Bonus obj = new Bonus();
        while (choice != 5) {
            System.out.println("Problem 1: Grade Evaluation System");
            System.out.println("Problem 2: Leap Year Check");
            System.out.println("Problem 3: Day of the week");
            System.out.println("Problem 4: Identify Default Values of Variables");
            System.out.println("Problem 5: Exit");
            System.out.println("Enter your choice: ");
            choice = sc.nextInt();
            switch (choice) {
                case 1:
                    gradeEvaluation();
                    break;
                case 2:
                    leapYearCheck();
                    break;
                case 3:
                    dayOfWeek(sc);
                    break;
                case 4:
                    defaultValues(obj);
                    break;
                case 5:
                    System.out.println("Exiting program...");
                    break;
                default:
                    System.out.println("Invalid choice");
            }
        }
        sc.close();
    }
}

/*//Without using method:-
import java.util.Scanner;
class Bonus {
    // Instance variables:-
    byte a;
    short b;
    int c;
    long d;
    float e;
    double f;
    char g;
    boolean h;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int choice = 0;
        Bonus obj = new Bonus();
        while (choice != 5) {
        System.out.println("Problem 1: Grade Evaluation System");
        System.out.println("Problem 2: Leap Year Check");
        System.out.println("Problem 3: Day of the week");
        System.out.println("Problem 4: Identify Default Values of Variables");
        System.out.println("Problem 5: Exit");
        System.out.println("Enter your choice: ");
        choice = sc.nextInt();
        switch (choice) {
            case 1:
                // Problem 1: Grade Evaluation System
                int marks_Maths = 80;
                int marks_Science = 85;
                int marks_History = 90;
                double Average_Marks =
                    (marks_Maths + marks_Science + marks_History) / 3.0;
                System.out.println("Average Marks: " + Average_Marks);
                if (Average_Marks >= 90) {
                    System.out.println("Grade: A");
                }
                else if (Average_Marks >= 70) {
                    System.out.println("Grade: B");
                }
                else if (Average_Marks >= 50) {
                    System.out.println("Grade: C");
                }
                else if (Average_Marks >= 30) {
                    System.out.println("Grade: D");
                }
                else {
                    System.out.println("Fail");
                }
                break;
            case 2:
                // Problem 2: Leap Year Check
                int year = 2024;
                if ((year % 4 == 0 && year % 100 != 0) ||
                    year % 400 == 0) {
                    System.out.println(year + " is a leap year");
                }
                else {
                    System.out.println(year + " is not a leap year");
                }
                break;
            case 3:
                // Problem 3: Day of the week
                System.out.println("Enter the number: ");
                int day = sc.nextInt();
                switch (day) {
                    case 1:
                        System.out.println("The day is Monday.");
                        break;
                    case 2:
                        System.out.println("The day is Tuesday.");
                        break;
                    case 3:
                        System.out.println("The day is Wednesday.");
                        break;
                    case 4:
                        System.out.println("The day is Thursday.");
                        break;
                    case 5:
                        System.out.println("The day is Friday.");
                        break;
                    case 6:
                        System.out.println("The day is Saturday.");
                        break;
                    case 7:
                        System.out.println("The day is Sunday.");
                        break;
                    default:
                        System.out.println("Invalid day");
                }
                break;
            case 4:
                // Problem 4: Default Values of Variables
                System.out.println("Default value of byte: " + obj.a);
                System.out.println("Default value of short: " + obj.b);
                System.out.println("Default value of int: " + obj.c);
                System.out.println("Default value of long: " + obj.d);
                System.out.println("Default value of float: " + obj.e);
                System.out.println("Default value of double: " + obj.f);
                System.out.println("Default value of char: " + (int)obj.g);
                System.out.println("Default value of boolean: " + obj.h);
                break;
            case 5:
                System.out.println("Exiting program...");
                break;

default:
    System.out.println("Invalid choice");
        }}
        sc.close();
    }
}*/