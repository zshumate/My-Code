import java.util.Scanner;

public class timeSec {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int hour;
		int min;
		int sec;
		
		System.out.println("Input time in hours: ");
		hour = scan.nextInt();
		System.out.println("Input time in minutes: ");
		min = scan.nextInt();
		System.out.println("Input time in seconds: ");
		sec = scan.nextInt();
		
		System.out.println("The time in seconds is "+(hour*60*60+min*60+sec));
	}
}
