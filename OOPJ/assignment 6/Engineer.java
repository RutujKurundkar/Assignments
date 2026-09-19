package employee;

public class Engineer extends Employee {

    private double overtime;

    public Engineer() {
        super();
    }

    public Engineer(String name, String address, int age, String gender,
                    double basicSalary, double overtime) {

        super(name, address, age, gender, basicSalary);
        setOvertime(overtime);
    }

    public double getOvertime() {
        return overtime;
    }

    public void setOvertime(double overtime) {
        if (overtime >= 0)
            this.overtime = overtime;
        else
            this.overtime = 0;
    }

    @Override
    public String getType() {
        return "Engineer";
    }

    @Override
    public String toString() {
        return "Engineer | Name: " + getName()
                + " | Address: " + getAddress()
                + " | Age: " + getAge()
                + " | Gender: " + getGender()
                + " | Basic Salary: " + getBasicSalary()
                + " | Overtime: " + getOvertime();
    }
}