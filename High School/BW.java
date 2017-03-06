//Zack Shumate
//AP Java
//Lab 6

import images.APImage;
import images.Pixel;
import java.util.Scanner;
import java.util.Random;

public class BW{
public static void main(String[] args){
	Scanner reader = new Scanner(System.in);
	APImage image = new APImage("smokey.jpg");
	image.draw();
	Random random = new Random();
	int r1=random.nextInt(255);
	int g1=random.nextInt(255);
	int b1=random.nextInt(255);

	int r2=random.nextInt(255);
	int g2=random.nextInt(255);
	int b2=random.nextInt(255);


	for(Pixel p : image){
		int red = p.getRed();
		int green = p.getGreen();
		int blue = p.getBlue();
		int average = (red+green+blue) /3;

		if (average < 128){
			p.setRed(r1);
			p.setGreen(g1);
			p.setBlue(b1);
		}
		else{
			p.setRed(r2);
			p.setGreen(g2);
			p.setBlue(b2);
		}
	}
	System.out.print("Press return to continue:");
	reader.nextLine();
	image.draw();
}
}
