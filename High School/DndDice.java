//Zack Shumate
//AP Java
//Lab 5

import java.util.Random;
import java.util.Scanner;
public class DndDice{
	public static void main(String [] args){
		Scanner reader1 = new Scanner(System.in);
		Scanner reader2 = new Scanner(System.in);
		Scanner reader3 = new Scanner(System.in);
		int num; //loop variable
		int dice; //dice you use

		Random MyRand = new Random();
		String answer="y"; //ask to repeat
		while(answer.equals("y")){
			int i=0; //loop counter
			long roll=0; //dice roll output
			System.out.print("What dice would you like to use (4, 6, 8, 10, 12, 20): ");
			dice = reader1.nextInt();
			System.out.print("How many dice would you like to roll: ");
			num = reader2.nextInt();

			while(i<num){
				roll+=MyRand.nextInt(dice) + 1;
				i++;
			}
			System.out.println("You rolled a "+roll);
			System.out.println("\nWould you like to play again? (y or n)");
			answer = reader3.nextLine();
		}
	}
}