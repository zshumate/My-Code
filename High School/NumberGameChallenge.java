//Zack Shumate
//AP Java
//Lab 9

import java.util.Random;
import java.util.Scanner;
public class NumberGameChallenge{
	public static void main(String [] args){
		Scanner reader1 = new Scanner(System.in);
		Scanner reader2 = new Scanner(System.in);
		Random random=new Random();

		String repeat="y"; //ask to repeat
		while(repeat.equals("y")){
			String question; //ask if too high, too low, or correct
			int answer;
			int guess;
			int tries=1; //# of guesses
			int h=100; //lowest of the guesses too high
			int l=0; //highest of the guesses too low

			guess=random.nextInt(100)+1;
			System.out.print(guess+". Is the number too high (h), too low (l), or correct (c).");
			question=reader1.nextLine();
			while(!question.equals("c")){
				if(question.equals("h")){
					h=guess;
					guess=((h-l)/2)+l;
					tries++;
				}
				if(question.equals("l")){
					l=guess;
					guess=((h-l)/2)+l;
					tries++;
				}
				System.out.print(guess+1+". Is the number too high (h), too low (l), or correct (c).");
				question=reader1.nextLine();
			}
			System.out.println("\nThe computer guessed it in "+tries+" guesses.");
			System.out.println("\nWould you like to play again? (y or n)");
			repeat=reader2.nextLine();
		}
	}
}