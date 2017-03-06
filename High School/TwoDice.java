//Zack Shumate
//AP Java
//Lab 5

import java.util.Random;
import java.util.Scanner;
public class TwoDice{
	public static void main(String [] args){
		Scanner reader = new Scanner(System.in);
		Random rand = new Random();
		Random rand2 = new Random();
		int num; //loop variable
		int dice; //dice roll output
		int i=0; //loop counter
		int [] array=new int [13];

		System.out.print("How many times would you like to roll the dice: ");
		num = reader.nextInt();
		for(int x=0; x<13; x++){
			array[x]=0;
		}
		while(i<num){
			dice=(rand.nextInt(6) + 1)+(rand2.nextInt(6) + 1);
			array[dice]++;
			i++;
		}
		for(int x=2; x<13; x++){
			System.out.println("\nNumber of "+x+" are "+array[x]);
		}
	}
}