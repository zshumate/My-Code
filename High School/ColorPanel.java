//Zack Shumate
//AP Java
//Lab 3-6

import javax.swing.*;
import java.awt.*;
public class ColorPanel extends JPanel{
	public ColorPanel(Color backColor){
		setBackground(backColor);
	}
	public void paintComponent(Graphics g){
		super.paintComponent(g);
		//"longer" line
		g.drawLine(50, 50, 200, 50);
		g.drawLine(50, 50, 25, 75);
		g.drawLine(50, 50, 25, 25);
		g.drawLine(200, 50, 225, 25);
		g.drawLine(200, 50, 225, 75);
		//"shorter" line
		g.drawLine(50, 100, 200, 100);
		g.drawLine(50, 100, 75, 75);
		g.drawLine(50, 100, 75, 125);
		g.drawLine(200, 100, 175, 75);
		g.drawLine(200, 100, 175 , 125);
	}
}