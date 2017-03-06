import java.util.Scanner;


public class square {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int length;
		
		System.out.println("Length of side of a square: ");
		length = scan.nextInt();
		
		System.out.println("The perimeter of the square is "+(4*length)+" and the area is "+(length*length));
	}

}
