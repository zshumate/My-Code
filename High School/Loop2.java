//Zack Shumate
//AP Java
//Lab 3-4

import java.util.Scanner;
public class Loop2{
	public static void main(String [] args){
		Scanner reader1 = new Scanner(System.in);
		Scanner reader2 = new Scanner(System.in);
		//input name
		String name;
		//number of times printed
		int repeat;
		//loop variable
		int i;
		System.out.print("Enter Name: ");
		name = reader1.nextLine();
		System.out.print("How many times to repeat: ");
		repeat = reader2.nextInt();
		for(i=0; i<=repeat; i++){
			System.out.println(name);
		}
		System.out.println("\nYou printed "+name+" "+repeat+" times");
	}
}