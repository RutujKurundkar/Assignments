package employee;

import java.io.*;

public class EncryptionDecryption {

    static int key = 5;

    static void encrypt(String sourceFile) {
        try {
            FileInputStream fis = new FileInputStream(sourceFile);
            DataInputStream dis = new DataInputStream(fis);

            FileOutputStream fos = new FileOutputStream("test_enc.txt");
            DataOutputStream dos = new DataOutputStream(fos);

            int data;

            while ((data = dis.read()) != -1) {
                dos.write(data + key);
            }

            dis.close();
            dos.close();

            System.out.println("File encrypted successfully.");
            System.out.println("Encrypted file stored as test_enc.txt");

        } catch (IOException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    static void decrypt(String encryptedFile) {
        try {
            FileInputStream fis = new FileInputStream(encryptedFile);
            DataInputStream dis = new DataInputStream(fis);

            FileOutputStream fos = new FileOutputStream("decrypt.txt");
            DataOutputStream dos = new DataOutputStream(fos);

            int data;

            while ((data = dis.read()) != -1) {
                dos.write(data - key);
            }

            dis.close();
            dos.close();

            System.out.println("File decrypted successfully.");
            System.out.println("Decrypted file stored as decrypt.txt");

        } catch (IOException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br =
                new BufferedReader(new InputStreamReader(System.in));

        while (true) {

            System.out.println("\n1. Encrypt");
            System.out.println("2. Decrypt");
            System.out.println("3. Exit");
            System.out.print("Enter choice: ");

            int choice = Integer.parseInt(br.readLine());

            switch (choice) {

            case 1:
                System.out.print("Enter source file path: ");
                String sourceFile = br.readLine();

                encrypt(sourceFile);
                break;

            case 2:
                System.out.print("Enter encrypted file path: ");
                String encryptedFile = br.readLine();

                decrypt(encryptedFile);
                break;

            case 3:
                System.out.println("Program terminated.");
                return;

            default:
                System.out.println("Invalid choice.");
            }
        }
    }
}