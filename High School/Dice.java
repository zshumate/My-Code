//Zack Shumate
//AP Java
//Lab 5

import java.util.Random;
import java.util.Scanner;
public class Dice{
	public static void main(String [] args){
		Scanner reader1 = new Scanner(System.in);
		Scanner reader2 = new Scanner(System.in);
		int num; //loop variable
		int dice; //dice roll output
		int d1=0; //if dice rolls a 1
		int d2=0; //if dice rolls a 2
		int d3=0; //if dice rolls a 3
		int d4=0; //if dice rolls a 4
		int d5=0; //if dice rolls a 5
		int d6=0; //if dice rolls a 6
		Random MyRand = new Random();
		String answer="y"; //ask to repeat
		while(answer.equals("y")){
			d1=0;
			d2=0;
			d3=0;
			d4=0;
			d5=0;
			d6=0;
			int i=0; //loop counter
			System.out.print("How many times would you like to roll a single dice: ");
			num = reader1.nextInt();
			while(i<num){
				dice=MyRand.nextInt(6) + 1;
				if(dice==1){
					d1++;
				}
				if(dice==2){
					d2++;
				}
				if(dice==3){
					d3++;
				}
				if(dice==4){
					d4++;
				}
				if(dice==5){
					d5++;
				}
				if(dice==6){
					d6++;
				}
				i++;
			}
			System.out.println("\nNumber of ones is "+d1);
			System.out.println("\nNumber of twos is "+d2);
			System.out.println("\nNumber of threes is "+d3);
			System.out.println("\nNumber of fours is "+d4);
			System.out.println("\nNumber of fives is "+d5);
			System.out.println("\nNumber of sixes is "+d6);
			System.out.println("\nWould you like to play again? (y or n)");
			answer = reader2.nextLine();
		}
	}
}