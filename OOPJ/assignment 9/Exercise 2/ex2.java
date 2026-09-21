import java.util.Random;
	import java.util.function.Supplier;

	public class ex2 {
	    public static void main(String[] args) {

	        Supplier<String> otp = () -> {
	            Random random = new Random();

	            String vowels = "AEIOU";
	            char first = vowels.charAt(random.nextInt(5));

	            String result = "" + first;

	            for (int i = 0; i < 4; i++) {
	                result += random.nextInt(10);
	            }

	            return result;
	        };

	        System.out.println(otp.get());
	    }
	}

