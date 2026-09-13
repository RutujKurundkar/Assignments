public class Manager extends Employee {

    private double hra;

    public Manager() {
        super();
    }

    public Manager(String name, String address, int age, String gender,
                   double basicSalary, double hra) {

        super(name, address, age, gender, basicSalary);
        setHra(hra);
    }

    public double getHra() {
        return hra;
    }

    public void setHra(double hra) {
        if (hra >= 0)
            this.hra = hra;
        else
            this.hra = 0;
    }

    @Override
    public String getType() {
        return "Manager";
    }

    @Override
    public String toString() {
        return "Manager | Name: " + getName()
                + " | Address: " + getAddress()
                + " | Age: " + getAge()
                + " | Gender: " + getGender()
                + " | Basic Salary: " + getBasicSalary()
                + " | HRA: " + getHra();
    }
}