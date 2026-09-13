public class Node {

    Employee employee;
    Node next;
    Node previous;

    public Node(Employee employee) {
        this.employee = employee;
        this.next = null;
        this.previous = null;
    }
}