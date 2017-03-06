import javax.swing.*;
import java.awt.*;

public class ColorPanel extends JPanel{
	public ColorPanel(Color backColor){
		setBackground(backColor);
	}
	public void paintComponent(Graphics g){
		super.paintComponent(g);
		
		g.drawLine(50, 250, 50, 150);
		g.drawLine(100, 250, 100, 150);
		g.drawLine(150, 250, 150, 150);
		g.drawLine(200, 250, 200, 150);
		g.drawLine(250, 250, 250, 150);
		g.drawLine(300, 250, 300, 150);
		g.drawLine(350, 250, 350, 150);
		g.drawLine(0, 225, 400, 225);
		g.drawLine(0, 175, 400, 175);
		
		g.drawRect(75, 100, 250, 100);
		g.drawLine(25, 100, 375, 100);
		g.drawLine(25, 100, 200, 25);
		g.drawLine(200, 25, 375, 100);
	}
}
