//Zack Shumate
//AP Java
//Lab 12

import java.util.Random;
class RandArray{
	public static void main(String [] args){
		double average=0.0;
		Random rand = new Random();
		int [] array=new int [10];
		for(int x=0; x<10; x++){
			array[x]=rand.nextInt(25) + 1;
		}
		for(int x=0; x<10; x++){
			average+=array[x];
		}
		average/=10.0;
		System.out.println("The average is "+average);
	}
}