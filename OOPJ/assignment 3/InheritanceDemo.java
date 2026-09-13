class Parent {

    public void displayParent() {
        System.out.println("This is parent class");
    }
}

class Child extends Parent {

    public void displayChild() {
        System.out.println("This is child class");
    }
}

public class InheritanceDemo {

    public static void main(String[] args) {

        Parent p = new Parent();
        Child c = new Child();

        p.displayParent();

        c.displayChild();

        c.displayParent();
    }
}