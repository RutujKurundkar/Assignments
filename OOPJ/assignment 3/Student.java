public class Student {

    String name;
    int roll_no;
    String phone_no;
    String address;

    public static void main(String[] args) {

        Student s1 = new Student();

        s1.roll_no = 2;
        s1.name = "John";

        System.out.println("Student 1:");
        System.out.println("Name: " + s1.name);
        System.out.println("Roll No: " + s1.roll_no);

        Student s2 = new Student();
        Student s3 = new Student();

        s2.name = "Sam";
        s2.roll_no = 1;
        s2.phone_no = "9876543210";
        s2.address = "Mumbai";

        s3.name = "John";
        s3.roll_no = 2;
        s3.phone_no = "9123456780";
        s3.address = "Pune";

        System.out.println();
        System.out.println("Student 2:");
        System.out.println("Name: " + s2.name);
        System.out.println("Roll No: " + s2.roll_no);
        System.out.println("Phone No: " + s2.phone_no);
        System.out.println("Address: " + s2.address);

        System.out.println();
        System.out.println("Student 3:");
        System.out.println("Name: " + s3.name);
        System.out.println("Roll No: " + s3.roll_no);
        System.out.println("Phone No: " + s3.phone_no);
        System.out.println("Address: " + s3.address);
}}