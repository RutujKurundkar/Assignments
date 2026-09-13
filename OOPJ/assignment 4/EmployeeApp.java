import java.util.Scanner;

public class EmployeeApp {

    static Scanner sc = new Scanner(System.in);
    static EmployeeList list = new EmployeeList();

    public static void main(String[] args) {

        int choice;

        do {

            System.out.println("\n===== EMPLOYEE MANAGEMENT SYSTEM =====");
            System.out.println("1. Add an Employee");
            System.out.println("2. Display");
            System.out.println("3. Sort");
            System.out.println("4. Save to File");
            System.out.println("5. Load from File");
            System.out.println("6. Exit");
            System.out.print("Enter choice: ");

            choice = sc.nextInt();

            switch (choice) {

            case 1:
                addEmployeeMenu();
                break;

            case 2:
                displayMenu();
                break;

            case 3:
                sortMenu();
                break;

            case 4:
                System.out.println("Save to File selected.");
                break;

            case 5:
                System.out.println("Load from File selected.");
                break;

            case 6:
                System.out.println("Application closed.");
                break;

            default:
                System.out.println("Invalid choice.");
            }

        } while (choice != 6);

        sc.close();
    }

    public static void addEmployeeMenu() {

        String choice;

        do {

            System.out.println("\n--- Add an Employee ---");
            System.out.println("a. Manager");
            System.out.println("b. Engineer");
            System.out.println("c. Sales Person");
            System.out.println("d. Exit to Main Menu");
            System.out.print("Enter choice: ");

            choice = sc.next();

            switch (choice) {

            case "a":
            case "A":
                addManager();
                break;

            case "b":
            case "B":
                addEngineer();
                break;

            case "c":
            case "C":
                addSalesPerson();
                break;

            case "d":
            case "D":
                break;

            default:
                System.out.println("Invalid choice.");
            }

        } while (!choice.equalsIgnoreCase("d"));
    }
    
    public static Employee getCommonDetails() {

        sc.nextLine();

        System.out.print("Enter name: ");
        String name = sc.nextLine();

        System.out.print("Enter address: ");
        String address = sc.nextLine();

        System.out.print("Enter age: ");
        int age = sc.nextInt();

        sc.nextLine();

        System.out.print("Enter gender: ");
        String gender = sc.nextLine();

        System.out.print("Enter basic salary: ");
        double salary = sc.nextDouble();

        return new Employee(name, address, age, gender, salary) {

            @Override
            public String getType() {
                return "Employee";
            }
        };
    }

    public static void addManager() {

        Employee e = getCommonDetails();

        System.out.print("Enter HRA: ");
        double hra = sc.nextDouble();

        Manager manager = new Manager(
                e.getName(),
                e.getAddress(),
                e.getAge(),
                e.getGender(),
                e.getBasicSalary(),
                hra
        );

        list.addEmployee(manager);

        System.out.println("Manager added successfully.");
    }

    public static void addEngineer() {

        Employee e = getCommonDetails();

        System.out.print("Enter Overtime: ");
        double overtime = sc.nextDouble();

        Engineer engineer = new Engineer(
                e.getName(),
                e.getAddress(),
                e.getAge(),
                e.getGender(),
                e.getBasicSalary(),
                overtime
        );

        list.addEmployee(engineer);

        System.out.println("Engineer added successfully.");
    }

    public static void addSalesPerson() {

        Employee e = getCommonDetails();

        System.out.print("Enter Commission: ");
        double commission = sc.nextDouble();

        SalesPerson salesPerson = new SalesPerson(
                e.getName(),
                e.getAddress(),
                e.getAge(),
                e.getGender(),
                e.getBasicSalary(),
                commission
        );

        list.addEmployee(salesPerson);

        System.out.println("Sales Person added successfully.");
    }

    public static void displayMenu() {

        int choice;

        do {

            System.out.println("\n--- Display ---");
            System.out.println("1. All Employees");
            System.out.println("2. First Employee");
            System.out.println("3. Next Employee");
            System.out.println("4. Previous Employee");
            System.out.println("5. Last Employee");
            System.out.println("6. Exit to Main Menu");
            System.out.print("Enter choice: ");

            choice = sc.nextInt();

            switch (choice) {

            case 1:
                list.displayAll();
                break;

            case 2:
                list.displayFirst();
                break;

            case 3:
                list.displayNext();
                break;

            case 4:
                list.displayPrevious();
                break;

            case 5:
                list.displayLast();
                break;

            case 6:
                break;

            default:
                System.out.println("Invalid choice.");
            }

        } while (choice != 6);
    }

    public static void sortMenu() {

        int choice;

        do {

            System.out.println("\n--- Sort ---");
            System.out.println("1. All Managers");
            System.out.println("2. All Engineers");
            System.out.println("3. All Sales Person");
            System.out.println("4. All Employees Alphabetic Ascending");
            System.out.println("5. All Employees Alphabetic Descending");
            System.out.println("6. Exit to Main Menu");
            System.out.print("Enter choice: ");

            choice = sc.nextInt();

            switch (choice) {

            case 1:
                list.sortByType("Manager");
                System.out.println("Managers sorted.");
                break;

            case 2:
                list.sortByType("Engineer");
                System.out.println("Engineers sorted.");
                break;

            case 3:
                list.sortByType("Sales Person");
                System.out.println("Sales Persons sorted.");
                break;

            case 4:
                list.sortAllAscending();
                System.out.println("Employees sorted in ascending order.");
                break;

            case 5:
                list.sortAllDescending();
                System.out.println("Employees sorted in descending order.");
                break;

            case 6:
                break;

            default:
                System.out.println("Invalid choice.");
            }

        } while (choice != 6);
    }
}