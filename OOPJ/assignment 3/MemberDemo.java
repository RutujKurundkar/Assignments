class Member {

    private String name;
    private int age;
    private String phoneNumber;
    private String address;
    private double salary;

    public void setName(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public int getAge() {
        return age;
    }

    public void setPhoneNumber(String phoneNumber) {
        this.phoneNumber = phoneNumber;
    }

    public String getPhoneNumber() {
        return phoneNumber;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    public String getAddress() {
        return address;
    }

    public void setSalary(double salary) {
        this.salary = salary;
    }

    public double getSalary() {
        return salary;
    }

    public void printSalary() {
        System.out.println("Salary: " + salary);
    }
}

class PrimeMembers extends Member {

    private int joiningYear;
    private double joiningFees;
    private boolean isActive;

    public void setJoiningYear(int joiningYear) {
        this.joiningYear = joiningYear;
    }

    public int getJoiningYear() {
        return joiningYear;
    }

    public void setJoiningFees(double joiningFees) {
        this.joiningFees = joiningFees;
    }

    public double getJoiningFees() {
        return joiningFees;
    }

    public void setActive(boolean active) {
        isActive = active;
    }

    public boolean getActive() {
        return isActive;
    }

    public void display() {
        System.out.println("Name: " + getName());
        System.out.println("Age: " + getAge());
        System.out.println("Phone Number: " + getPhoneNumber());
        System.out.println("Address: " + getAddress());
        System.out.println("Salary: " + getSalary());
        System.out.println("Joining Year: " + joiningYear);
        System.out.println("Joining Fees: " + joiningFees);
        System.out.println("Active: " + isActive);
    }
}

public class MemberDemo {

    public static void main(String[] args) {

        PrimeMembers member = new PrimeMembers();

        System.out.print("Enter name: ");
        member.setName(ConsoleInput.getString());

        System.out.print("Enter age: ");
        member.setAge(ConsoleInput.getInt());

        System.out.print("Enter phone number: ");
        member.setPhoneNumber(ConsoleInput.getString());

        System.out.print("Enter address: ");
        member.setAddress(ConsoleInput.getString());

        System.out.print("Enter salary: ");
        member.setSalary(ConsoleInput.getDouble());

        System.out.print("Enter joining year: ");
        member.setJoiningYear(ConsoleInput.getInt());

        System.out.print("Enter joining fees: ");
        member.setJoiningFees(ConsoleInput.getDouble());

        System.out.print("Is member active? (true/false): ");
        member.setActive(Boolean.parseBoolean(ConsoleInput.getString()));

        System.out.println();

        member.display();

        System.out.println();

        member.printSalary();
    }
}
