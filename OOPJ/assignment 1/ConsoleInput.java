import java.io.BufferedReader;
import java.io.InputStreamReader;

public class ConsoleInput {

    private static BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));

    public static int getInt() {
        try {
        	return Integer.parseInt(br.readLine().trim());        } catch (Exception e) {
            e.printStackTrace();
            return 0;
        }
    }

    public static double getDouble() {
        try {
            return Double.parseDouble(br.readLine());
        } catch (Exception e) {
            return 0.0;
        }
    }

    public static String getString() {
        try {
            return br.readLine();
        } catch (Exception e) {
            return "";
        }
    }

    public static char getChar() {
        try {
            return br.readLine().charAt(0);
        } catch (Exception e) {
            return '\0';
        }
    }
}
