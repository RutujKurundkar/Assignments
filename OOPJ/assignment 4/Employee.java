public abstract class Employee {

    private String name;
    private String address;
    private int age;
    private String gender;
    private double basicSalary;

    public Employee() {
    }

    public Employee(String name, String address, int age, String gender, double basicSalary) {
        setName(name);
        setAddress(address);
        setAge(age);
        setGender(gender);
        setBasicSalary(basicSalary);
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        if (name != null && name.length() > 0)
            this.name = name;
        else
            this.name = "Unknown";
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        if (address != null && address.length() > 0)
            this.address = address;
        else
            this.address = "Unknown";
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        if (age >= 18 && age <= 60)
            this.age = age;
        else
            this.age = 18;
    }

    public String getGender() {
        return gender;
    }

    public void setGender(String gender) {
        if (gender != null && gender.length() > 0)
            this.gender = gender;
        else
            this.gender = "Unknown";
    }

    public double getBasicSalary() {
        return basicSalary;
    }

    public void setBasicSalary(double basicSalary) {
        if (basicSalary >= 0)
            this.basicSalary = basicSalary;
        else
            this.basicSalary = 0;
    }

    public abstract String getType();
}