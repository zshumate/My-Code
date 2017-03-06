//Zack Shumate
//AP Java
//Lab 3-4

import java.util.Scanner;
public class Loop{
	public static void main(String [] args){
		Scanner reader1 = new Scanner(System.in);
		//input name
		String name;
		//loop variable
		int i;
		System.out.print("Enter Name: ");
		name = reader1.nextLine();
		for(i=0; i<=1000; i++){
			System.out.println(name);
		}
	}
}