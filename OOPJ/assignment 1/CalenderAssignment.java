public class CalenderAssignment {
    public static void main(String[] args) {

        Date d = new Date();

        int choice;

        do {
            System.out.println("1. Set Date");
            System.out.println("2. Add Days");
            System.out.println("3. Add Months");
            System.out.println("4. Add Years");
            System.out.println("5. Display");
            System.out.println("6. Compare Dates");
            System.out.println("7. Exit");
            System.out.println("Enter your choice:");

            choice = ConsoleInput.getInt();

            switch (choice) {

                case 1:
                    System.out.println("Enter day:");
                    int day = ConsoleInput.getInt();

                    System.out.println("Enter month:");
                    int month = ConsoleInput.getInt();

                    System.out.println("Enter year:");
                    int year = ConsoleInput.getInt();

                    d.setDate(day, month, year);
                    break;

                case 2:
                    System.out.println("Enter number of days to add:");
                    int days = ConsoleInput.getInt();

                    d.addDays(days);
                    break;

                case 3:
                    System.out.println("Enter number of months to add:");
                    int months = ConsoleInput.getInt();

                    d.addMonths(months);
                    break;

                case 4:
                    System.out.println("Enter number of years to add:");
                    int years = ConsoleInput.getInt();

                    d.addYears(years);
                    break;

                case 5:
                    d.display();
                    break;

                case 6:
                    System.out.println("Compare Dates not implemented.");
                    break;

                case 7:
                    System.out.println("Exiting...");
                    break;

                default:
                    System.out.println("Invalid choice.");
            }

        } while (choice != 7);
    }
}
