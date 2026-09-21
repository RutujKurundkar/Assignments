import java.util.ArrayList;
import java.util.Scanner;
import java.util.function.Predicate;
import java.util.function.Function;

class Transaction {
    int txId;
    float txAmount;
    boolean txStatus;
    boolean txArrears;

    public Transaction(int txId, float txAmount, boolean txStatus, boolean txArrears) {
        this.txId = txId;
        this.txAmount = txAmount;
        this.txStatus = txStatus;
        this.txArrears = txArrears;
    }

    public String toString() {
        return txId + " " + txAmount + " " + txStatus + " " + txArrears;
    }
}

class Program {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        ArrayList<Transaction> transactions = new ArrayList<>();
        for (int i = 0; i < 5; i++) {

            System.out.println("Enter Transaction " + (i + 1));

            System.out.print("Transaction ID: ");
            int id = sc.nextInt();

            System.out.print("Transaction Amount: ");
            float amount = sc.nextFloat();

            System.out.print("Transaction Status (true/false): ");
            boolean status = sc.nextBoolean();

            System.out.print("Transaction Arrears (true/false): ");
            boolean arrears = sc.nextBoolean();

            transactions.add(new Transaction(id, amount, status, arrears));        }

        Predicate<Transaction> amountGreaterThan5000 =
                t -> t.txAmount > 5000;

        Predicate<Transaction> statusFalse =
                t -> t.txStatus == false;

            Function<Transaction, Float> amountDue =
                t -> {
                    if (t.txArrears)
                        return t.txAmount + 500 + (t.txAmount * 18 / 100);
                    else
                        return t.txAmount;
                };

        System.out.println("\nTransactions with amount > 5000:");

        for (Transaction t : transactions) {
            if (amountGreaterThan5000.test(t))
                System.out.println(t);
        }

        System.out.println("\nTransactions with status false:");

        for (Transaction t : transactions) {
            if (statusFalse.test(t))
                System.out.println(t);
        }

        System.out.println("\nAmount Due:");

        for (Transaction t : transactions) {
            System.out.println("Transaction ID: " + t.txId);
            System.out.println("Amount Due: " + amountDue.apply(t));
        }

        sc.close();
    }
}