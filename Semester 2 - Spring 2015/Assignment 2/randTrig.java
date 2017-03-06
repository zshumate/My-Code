import java.util.Random;


public class randTrig {

	public static void main(String[] args) {
		Random rand = new Random();
		int num = rand.nextInt(21)+20;
		
		System.out.println("Sine of " + num + " is " + Math.sin((double)num));
		System.out.println("Cosine of " + num + " is " + Math.cos((double)num));
		System.out.println("Tangent of " + num + " is " + Math.tan((double)num));
		
	}

}
