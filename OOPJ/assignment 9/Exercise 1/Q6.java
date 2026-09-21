import java.util.function.Supplier;
import java.time.LocalDate;

public class Q6 {
    public static void main(String[] args) {
        Supplier<LocalDate> date = () -> LocalDate.now();

        System.out.println(date.get());
    }
}