//Zack Shumate
//AP Java
//Lab 9

import java.util.Random;
import java.util.Scanner;
public class NumberGame{
	public static void main(String [] args){
		int answer;
		int guess;
		Scanner reader1 = new Scanner(System.in);
		Scanner reader2 = new Scanner(System.in);
		Random random = new Random();

		String repeat="y"; //ask to repeat
		while(repeat.equals("y")){
			int tries=1; //# of guesses
			answer=random.nextInt(100) + 1;
			System.out.print("\nI am thinking of a number between 1 and 100. What is your first guess? ");
			guess=reader1.nextInt();
			while(guess!=answer){
				if(guess<answer){
					System.out.print("That is too low. Try again. ");
					guess=reader1.nextInt();
					tries++;
				}
				else if(guess>answer){
					System.out.print("That is too high. Try again. ");
					guess=reader1.nextInt();
					tries++;
				}
			}
			System.out.println("\nGreat! You guessed it in "+tries+" guesses.");
			System.out.println("\nWould you like to play again? (y or n)");
			repeat=reader2.nextLine();
		}
	}
}
