import java.util.Scanner;
public class Momentum{
	public static void main(String [] args){
		Scanner reader1 = new Scanner(System.in);
		Scanner reader2 = new Scanner(System.in);
		double mass;
		double velocity;
		double momentum;
		System.out.print("Enter Mass: ");
		mass = reader1.nextDouble();
		System.out.print("Enter Velocity: ");
		velocity = reader2.nextDouble();
		momentum = mass * velocity;
		System.out.print("The Momentum is ");
		System.out.println(momentum);
	}
}