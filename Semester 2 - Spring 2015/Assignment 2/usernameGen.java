import java.util.Scanner;
import java.util.Random;


public class usernameGen {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String firstName;
		String lastName;
		Random rand = new Random();
		
		System.out.println("What is your first name?");
		firstName = scan.nextLine();
		System.out.println("What is your last name?");
		lastName = scan.nextLine();
		
		System.out.println("Your username is: " + firstName.substring(0, 1) + lastName.substring(0, 5) + (rand.nextInt(90)+10));
	}

}
