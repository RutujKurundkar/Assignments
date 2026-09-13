public class Employee {

    double salary;
    int hours;

    public void getInfo(double sal, int hrs) {
        salary = sal;
        hours = hrs;
    }

    public void addSal() {
        if (salary < 500) {
            salary = salary + 10;
        }
    }

    public void addWork() {
        if (hours > 6) {
            salary = salary + 5;
        }
    }

    public static void main(String[] args) {

        Employee e = new Employee();

        System.out.println("Enter salary:");
        double sal = ConsoleInput.getDouble();

        System.out.println("Enter hours of work per day:");
        int hrs = ConsoleInput.getInt();

        e.getInfo(sal, hrs);
        e.addSal();
        e.addWork();

        System.out.println("Final salary: $" + e.salary);
    }
}
