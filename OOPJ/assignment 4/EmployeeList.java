public class EmployeeList {

    private Node head;
    private Node tail;
    private Node current;

    public EmployeeList() {
        head = null;
        tail = null;
        current = null;
    }

    public void addEmployee(Employee employee) {

        Node newNode = new Node(employee);

        if (head == null) {
            head = newNode;
            tail = newNode;
            current = newNode;
        } else {
            tail.next = newNode;
            newNode.previous = tail;
            tail = newNode;
        }
    }

    public void displayAll() {

        if (head == null) {
            System.out.println("No employees available.");
            return;
        }

        Node temp = head;

        while (temp != null) {
            System.out.println(temp.employee);
            temp = temp.next;
        }
    }

    public void displayFirst() {

        if (head == null) {
            System.out.println("No employees available.");
            return;
        }

        current = head;
        System.out.println(current.employee);
    }

    public void displayNext() {

        if (current == null) {
            System.out.println("No employee selected.");
            return;
        }

        if (current.next == null) {
            System.out.println("Already at last employee.");
            return;
        }

        current = current.next;
        System.out.println(current.employee);
    }

    public void displayPrevious() {

        if (current == null) {
            System.out.println("No employee selected.");
            return;
        }

        if (current.previous == null) {
            System.out.println("Already at first employee.");
            return;
        }

        current = current.previous;
        System.out.println(current.employee);
    }

    public void displayLast() {

        if (tail == null) {
            System.out.println("No employees available.");
            return;
        }

        current = tail;
        System.out.println(current.employee);
    }

    public void sortByType(String type) {

        if (head == null) {
            System.out.println("No employees available.");
            return;
        }

        Node i = head;

        while (i != null) {

            Node j = i.next;

            while (j != null) {

                if (i.employee.getType().equals(type)
                        && j.employee.getType().equals(type)) {

                    if (i.employee.getName()
                            .compareToIgnoreCase(j.employee.getName()) > 0) {

                        Employee temp = i.employee;
                        i.employee = j.employee;
                        j.employee = temp;
                    }
                }

                j = j.next;
            }

            i = i.next;
        }
    }

    public void sortAllAscending() {

        if (head == null)
            return;

        Node i = head;

        while (i != null) {

            Node j = i.next;

            while (j != null) {

                if (i.employee.getName()
                        .compareToIgnoreCase(j.employee.getName()) > 0) {

                    Employee temp = i.employee;
                    i.employee = j.employee;
                    j.employee = temp;
                }

                j = j.next;
            }

            i = i.next;
        }
    }

    public void sortAllDescending() {

        if (head == null)
            return;

        Node i = head;

        while (i != null) {

            Node j = i.next;

            while (j != null) {

                if (i.employee.getName()
                        .compareToIgnoreCase(j.employee.getName()) < 0) {

                    Employee temp = i.employee;
                    i.employee = j.employee;
                    j.employee = temp;
                }

                j = j.next;
            }

            i = i.next;
        }
    }
}