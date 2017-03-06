import java.util.Scanner;
public class Echo{
	public static void main(String [] args){
		Scanner reader1 = new Scanner(System.in);
		Scanner reader2 = new Scanner(System.in);
		Scanner reader3 = new Scanner(System.in);
		Scanner reader4 = new Scanner(System.in);
		String firstName;
		String lastName;
		int year;
		String phone;
		System.out.print("Enter First Name: ");
		firstName = reader1.nextLine();
		System.out.print("Enter Last Name: ");
		lastName = reader2.nextLine();
		System.out.print("Enter Class Year: ");
		year = reader3.nextInt();
		System.out.print("Enter Campus Phone: ");
		phone = reader4.nextLine();
		System.out.println("\n You are " + firstName + " " + lastName);
		System.out.println("Class of " + year);
		System.out.println("Campus phone is " + phone);
	}
}