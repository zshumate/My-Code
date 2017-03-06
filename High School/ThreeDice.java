//Zack Shumate
//AP Java
//Lab 1

import java.util.Random;
import java.util.Scanner;
public class ThreeDice{
	public static void main(String [] args){
		Scanner reader = new Scanner(System.in);
		Random rand = new Random();
		Random rand2 = new Random();
		Random rand3 = new Random();
		int num; //loop variable
		int dice; //dice roll output
		int i=0; //loop counter
		int [] array=new int [19];

		System.out.print("How many times would you like to roll the dice: ");
		num = reader.nextInt();
		for(int x=0; x<13; x++){
			array[x]=0;
		}
		while(i<num){
			dice=(rand.nextInt(6) + 1)+(rand2.nextInt(6) + 1)+(rand3.nextInt(6) + 1);
			array[dice]++;
			i++;
		}
		for(int x=3; x<19; x++){
			System.out.println("\nNumber of "+x+" are "+array[x]);
		}
	}
}

//10 and 11

//3 and 18

//bell curve

//the numbers on the ends of the spectrum of possible numbers have fewer combinations of dice
//rolls resulting in fewer numbers than those in the middle of the spectrum, like 10 and 11,
//which have multiple possible combinations.