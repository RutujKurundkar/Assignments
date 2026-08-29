#include <iostream>
using namespace std;

class Employee {
private:
    int empId;
    string name;
    string department;
    char grade;
    double basicSalary;
    bool isActive;
    static int employeeCount;

public:

    // Constructor
    Employee() {
        empId = 1001 + employeeCount;
        employeeCount++;

        name = "";
        department = "";
        grade = '\0';
        basicSalary = 0;
        isActive = true;
    }


    // Setter for name
    void setName(const string& n) {
        if (n.empty()) {
            cout << "ERROR: Name cannot be empty. Value rejected." << endl;
        }
        else {
            name = n;
        }
    }


    // Setter for department
    void setDepartment(const string& dept) {
        if (dept == "Engineering" ||
            dept == "HR" ||
            dept == "Finance" ||
            dept == "Operations") {

            department = dept;
        }
        else {
            cout << "ERROR: '" << dept
                 << "' is not a registered department." << endl;
        }
    }


    // Setter for grade
    void setGrade(char g) {
        if (g == 'A' || g == 'B' || g == 'C' || g == 'D') {
            grade = g;
        }
        else {
            cout << "ERROR: Invalid grade '" << g
                 << "'. Accepted values: A, B, C, D." << endl;
        }
    }


    // Setter for basic salary
    void setBasicSalary(double salary) {
        if (salary > 10000 && salary < 500000) {
            basicSalary = salary;
        }
        else {
            cout << "ERROR: Salary must be between Rs.10,000 and Rs.5,00,000. Value rejected."
                 << endl;
        }
    }


    // Deactivate employee
    void deactivate() {
        isActive = false;
    }


    // Getters
    int getEmpId() const {
        return empId;
    }

    string getName() const {
        return name;
    }

    string getDepartment() const {
        return department;
    }

    char getGrade() const {
        return grade;
    }

    double getBasicSalary() const {
        return basicSalary;
    }

    bool getIsActive() const {
        return isActive;
    }


    // Calculate allowances
    double computeAllowances() const {

        if (grade == 'A') {
            return basicSalary * 0.40;
        }
        else if (grade == 'B') {
            return basicSalary * 0.30;
        }
        else if (grade == 'C') {
            return basicSalary * 0.20;
        }
        else {
            return basicSalary * 0.10;
        }
    }


    // Calculate gross salary
    double computeGrossSalary() const {
        return basicSalary + computeAllowances();
    }


    // Calculate tax
    double computeTax() const {

        double gross = computeGrossSalary();

        if (gross <= 50000) {
            return 0;
        }
        else if (gross <= 100000) {
            return (gross - 50000) * 0.10;
        }
        else {
            return 5000 + (gross - 100000) * 0.20;
        }
    }


    // Calculate net salary
    double computeNetSalary() const {
        return computeGrossSalary() - computeTax();
    }


    // Print payslip
    void printPayslip() const {

        cout << "============================================" << endl;
        cout << "EMPLOYEE PAYSLIP - AUG 2026" << endl;
        cout << "============================================" << endl;

        cout << "Emp ID      : " << empId << endl;
        cout << "Name        : " << name << endl;
        cout << "Department  : " << department << endl;
        cout << "Grade       : " << grade << endl;

        cout << "Status      : ";

        if (isActive) {
            cout << "Active";
        }
        else {
            cout << "Inactive";
        }

        cout << endl;

        cout << "--------------------------------------------" << endl;

        cout << "Basic Salary     : Rs. "
             << basicSalary << endl;

        cout << "Allowances       : Rs. "
             << computeAllowances() << endl;

        cout << "Gross Salary     : Rs. "
             << computeGrossSalary() << endl;

        cout << "--------------------------------------------" << endl;

        cout << "Tax Deduction    : Rs. "
             << computeTax() << endl;

        cout << "Net Salary       : Rs. "
             << computeNetSalary() << endl;

        cout << "============================================" << endl;
    }


    // Accept employee details
    void acceptDetails() {

        string n;
        string dept;
        char g;
        double salary;


        // Name
        do {
            cout << "Enter name: ";
            getline(cin >> ws, n);

            setName(n);

        } while (name.empty());


        // Department
        do {
            cout << "Enter department: ";
            cin >> dept;

            setDepartment(dept);

        } while (department.empty());


        // Grade
        do {
            cout << "Enter grade: ";
            cin >> g;

            setGrade(g);

        } while (grade == '\0');


        // Basic salary
        do {
            cout << "Enter basic salary: ";
            cin >> salary;

            setBasicSalary(salary);

        } while (basicSalary == 0);
    }


    // Static getter
    static int getEmployeeCount() {
        return employeeCount;
    }
};


// Initialize static member
int Employee::employeeCount = 0;


int main() {

    // One object on stack
    Employee e1;

    // Two objects on heap
    Employee* e2 = new Employee();
    Employee* e3 = new Employee();


    // Accept details
    e1.acceptDetails();
    e2->acceptDetails();
    e3->acceptDetails();


    // These cause compiler errors because the members are private.
    /*e1.empId = 999;
    e1.basicSalary = -1000;
    ..\Payrollengine.cpp:283:8: error: 'int Employee::empId' is private within this context
      283 |     e1.empId = 999;
          |        ^~~~~
    ..\Payrollengine.cpp:6:9: note: declared private here
        6 |     int empId;
          |         ^~~~~
    ..\Payrollengine.cpp:283:8: note: field 'int Employee::empId' can be accessed via 'int Employee::getEmpId() const'
      283 |     e1.empId = 999;
          |        ^~~~~
          |        getEmpId()
    ..\Payrollengine.cpp:284:8: error: 'double Employee::basicSalary' is private within this context
      284 |     e1.basicSalary = -1000;
          |        ^~~~~~~~~~~
    ..\Payrollengine.cpp:10:12: note: declared private here
       10 |     double basicSalary;
          |            ^~~~~~~~~~~
    ..\Payrollengine.cpp:284:8: note: field 'double Employee::basicSalary' can be accessed via 'double Employee::getBasicSalary() const'
      284 |     e1.basicSalary = -1000;
          |        ^~~~~~~~~~~
          |        getBasicSalary()
*/

    // Print payslips
    e1.printPayslip();
    e2->printPayslip();
    e3->printPayslip();


    // Simulate a resignation
    e3->deactivate();

    if (!e3->getIsActive()) {
        cout << e3->getName()
             << " is no longer active. Payroll skipped."
             << endl;
    }


    // Total employees
    cout << "Total Employees : "
         << Employee::getEmployeeCount()
         << endl;


    // Delete heap objects
    delete e2;
    delete e3;


    return 0;
}
