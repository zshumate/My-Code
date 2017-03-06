//Zack Shumate
//AP Java
//Lab 10

import javax.swing.*;

public class ThermometerConvert{
	public static void main(String[] args){
		ThermometerGUI theGUI=new ThermometerGUI();
		theGUI.setTitle("F to C Converter");
		theGUI.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		theGUI.pack();
		theGUI.setVisible(true);
	}
}