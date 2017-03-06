//Zack Shumate
//AP Java
//Lab 3-4

import java.util.Scanner;
public class Pay{
	public static void main(String [] args){
		Scanner reader1 = new Scanner(System.in);
		Scanner reader2 = new Scanner(System.in);
		Scanner reader3 = new Scanner(System.in);
		//hourly wage
		double wage;
		//total regular hours
		double hours;
		double overtime;
		//total weekly pay
		double pay;
		System.out.print("Enter hourly wage: ");
		wage = reader1.nextDouble();
		System.out.print("Enter total regular hours: ");
		hours = reader2.nextDouble();
		System.out.print("Enter total overtime: ");
		overtime = reader3.nextDouble();
		pay = hours*wage+overtime*1.5*wage;
		System.out.println("\nYour weekly pay is $"+pay);
	}

}