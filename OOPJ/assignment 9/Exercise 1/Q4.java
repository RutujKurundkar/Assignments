import java.util.function.Supplier;
import java.util.Random;

public class Q4 {
    public static void main(String[] args) {
        Supplier<Integer> random = () -> new Random().nextInt(900) + 100;

        System.out.println(random.get());
    }
}
