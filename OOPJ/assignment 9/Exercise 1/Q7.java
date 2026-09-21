import java.util.function.Predicate;

public class Q7 {
    public static void main(String[] args) {
        Predicate<Integer> prime = n -> {
            if (n < 2)
                return false;

            for (int i = 2; i <= Math.sqrt(n); i++) {
                if (n % i == 0)
                    return false;
            }

            return true;
        };

        int n = 18;

        System.out.println(prime.test(n));
    }
}