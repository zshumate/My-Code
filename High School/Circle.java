//Zack Shumate
//AP Java
//Lab 3-6

import java.util.Scanner;
public class Circle{
	public static void main(String [] args){
		Scanner reader1 = new Scanner(System.in);
		//r is radius
		double r;
		double diameter;
		double circumference;
		double surfaceArea;
		double volume;
		System.out.print("Enter Radius: ");
		r = reader1.nextDouble();
		diameter = 2.0*r;
		circumference = diameter*3.14;
		surfaceArea = 4*3.14*(r*r);
		volume = (4/3)*3.14*(r*r*r);
		System.out.println("The diameter is "+diameter);
		System.out.println("The circumference is "+circumference);
		System.out.println("The surface area is "+surfaceArea);
		System.out.println("The volume is "+volume);
	}
}