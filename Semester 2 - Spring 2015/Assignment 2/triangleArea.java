import java.util.Scanner;

public class triangleArea {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		double a;
		double b;
		double c;
		
		System.out.println("What is the length of side A?");
		a = scan.nextDouble();
		System.out.println("What is the length of side B?");
		b = scan.nextDouble();
		System.out.println("What is the length of side C?");
		c = scan.nextDouble();
		double s = (a+b+c)/2;
		double area = Math.sqrt(s*(s-a)*(s-b)*(s-c));
		
		System.out.print("The area of the triangle is: ");
		System.out.printf("%.3f" , area);
	}

}
