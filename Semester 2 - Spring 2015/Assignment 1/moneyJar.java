import java.util.Scanner;


public class moneyJar {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int quarter;
		int dime;
		int nickel;
		int penny;
		
		System.out.println("How many quarters are in the jar: ");
		quarter = scan.nextInt();
		System.out.println("How many dimes are in the jar: ");
		dime = scan.nextInt();
		System.out.println("How many nickels are in the jar: ");
		nickel = scan.nextInt();
		System.out.println("How many pennies are in the jar: ");
		penny = scan.nextInt();
		
		System.out.println("There is $"+(quarter*.25+dime*.1+nickel*.05+penny*.01)+" in the jar");
	}

}
