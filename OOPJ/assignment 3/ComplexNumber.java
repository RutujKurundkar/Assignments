public class ComplexNumber {

    int number1;
    int number2;

    public int getNumber1() {
        return number1;
    }

    public void setNumber1(int number1) {
        this.number1 = number1;
    }

    public int getNumber2() {
        return number2;
    }

    public void setNumber2(int number2) {
        this.number2 = number2;
    }

    public int computeComplexNumber() {
        return number1 * number2;
    }

    public static void main(String[] args) {

        ComplexNumber[] arr = new ComplexNumber[5];

        for (int i = 0; i < 5; i++) {

            arr[i] = new ComplexNumber();

            System.out.println("Enter number 1:");
            int number1 = ConsoleInput.getInt();

            System.out.println("Enter number 2:");
            int number2 = ConsoleInput.getInt();

            arr[i].setNumber1(number1);
            arr[i].setNumber2(number2);
        }

        for (int i = 0; i < 5; i++) {
        	System.out.println ("The product is: ");           
        	System.out.println(arr[i].computeComplexNumber());
        }
    }
}