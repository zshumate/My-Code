//Zack Shumate
//AP Java
//Lab 3-4

import java.util.Scanner;
public class ImprovedPay{
	public static void main(String [] args){
		Scanner reader1 = new Scanner(System.in);
		Scanner reader2 = new Scanner(System.in);
		Scanner reader3 = new Scanner(System.in);
		Scanner reader4 = new Scanner(System.in);
		String firstName;
		String lastName;
		//hourly wage
		double wage;
		//total regular hours
		int hours;
		//regular pay
		double pay;
		double overtime=0;
		double grossPay;
		double netPay;
		System.out.print("Enter your first name: ");
		firstName = reader1.nextLine();
		System.out.print("Enter your last name: ");
		lastName = reader2.nextLine();
		System.out.print("Enter hourly wage: ");
		wage = reader3.nextDouble();
		System.out.print("Enter total hours: ");
		hours = reader4.nextInt();
		if(hours<=40){
			pay=hours*wage;
		}
		else{
			if(hours<=60){
				pay=40.0*wage;
				overtime=1.5*(hours-40)*wage;
			}
			else{
				pay=40.0*wage;
				overtime=1.5*20.0*wage+2.0*(hours-60)*wage;
			}
		}
		grossPay=pay+overtime;
		netPay=grossPay-(grossPay*0.3);
		System.out.println("\n"+firstName+" "+lastName);
		System.out.println("Hours worked is "+hours);
		System.out.println("Regular pay is $"+pay);
		System.out.println("Overtime pay is $"+overtime);
		System.out.println("Gross pay is $"+grossPay);
		System.out.println("Net Total pay is $"+netPay);
	}
}