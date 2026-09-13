public class Complex {

    int real1;
    int imaginary1;
    int real2;
    int imaginary2;

    public Complex(int r1, int i1, int r2, int i2) {
        real1 = r1;
        imaginary1 = i1;
        real2 = r2;
        imaginary2 = i2;
    }

    public void sum() {
        int real = real1 + real2;
        int imaginary = imaginary1 + imaginary2;

        System.out.println("Sum: " + real + " + " + imaginary + "i");
    }

    public void difference() {
        int real = real1 - real2;
        int imaginary = imaginary1 - imaginary2;

        System.out.println("Difference: " + real + " + " + imaginary + "i");
    }

    public void product() {
        int real = (real1 * real2) - (imaginary1 * imaginary2);
        int imaginary = (real1 * imaginary2) + (imaginary1 * real2);

        System.out.println("Product: " + real + " + " + imaginary + "i");
    }

    public static void main(String[] args) {

        System.out.println("Enter real part of first complex number:");
        int r1 = ConsoleInput.getInt();

        System.out.println("Enter imaginary part of first complex number:");
        int i1 = ConsoleInput.getInt();

        System.out.println("Enter real part of second complex number:");
        int r2 = ConsoleInput.getInt();

        System.out.println("Enter imaginary part of second complex number:");
        int i2 = ConsoleInput.getInt();

        Complex c = new Complex(r1, i1, r2, i2);

        c.sum();
        c.difference();
        c.product();
    }
}