//Zack Shumate
//AP Java
//Lab 6

import images.APImage;
import images.Pixel;
import java.util.Scanner;

public class Sepia{
	public static void main(String[] args){
		Scanner reader = new Scanner(System.in);
		APImage image = new APImage("smokey.jpg");
		image.draw();

		for(Pixel p : image){
			int red = p.getRed();
			int green = p.getGreen();
			int blue = p.getBlue();
			int average = (red+green+blue)/3;

			p.setRed(average);
			p.setGreen(average);
			p.setBlue(average);

			if(red<63){
				red=(int)(red*1.1);
				p.setRed(red);
				blue=(int)(blue*0.9);
				p.setBlue(blue);

			}
			else if(red<192){
				red=(int)(red*1.15);
				p.setRed(red);
				blue=(int)(blue*0.85);
				p.setBlue(blue);
			}
			else{
				red*=1.08;
				red=Math.min(red, 255);
				p.setRed(red);
				blue=(int)(blue*0.93);
				p.setBlue(blue);
			}
		}
		System.out.print("Press return to continue:");
		reader.nextLine();
		image.draw();
	}
}