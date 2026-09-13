public class SalesPerson extends Employee {

    private double commission;

    public SalesPerson() {
        super();
    }

    public SalesPerson(String name, String address, int age, String gender,
                       double basicSalary, double commission) {

        super(name, address, age, gender, basicSalary);
        setCommission(commission);
    }

    public double getCommission() {
        return commission;
    }

    public void setCommission(double commission) {
        if (commission >= 0)
            this.commission = commission;
        else
            this.commission = 0;
    }

    @Override
    public String getType() {
        return "Sales Person";
    }

    @Override
    public String toString() {
        return "Sales Person | Name: " + getName()
                + " | Address: " + getAddress()
                + " | Age: " + getAge()
                + " | Gender: " + getGender()
                + " | Basic Salary: " + getBasicSalary()
                + " | Commission: " + getCommission();
    }
}