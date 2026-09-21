import java.util.function.BiFunction;

public class Q8 {
    public static void main(String[] args) {

        BiFunction<String, String, String> concat = (a, b) -> a + b;

        String result = concat.apply("Hello ", "World");

        System.out.println(result);
    }
}