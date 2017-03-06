//Zack Shumate
//AP Java
//Lab 3-6

import javax.swing.*;
import java.awt.*;
public class Illusion{
	public static void main(String [] args){
		JFrame theGUI =  new JFrame();
		theGUI.setTitle("Illusion");
		theGUI.setSize(300, 200);
		theGUI.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		ColorPanel panel = new ColorPanel(Color.white);
		Container pane = theGUI.getContentPane();
		pane.add(panel);
		theGUI.setVisible(true);
	}
}