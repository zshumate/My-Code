import java.awt.*;
import java.awt.event.*;

import javax.swing.*;

public class ColorLine extends JPanel{
	private Timer timer;
	private int x;
	
	public ColorLine(){
		timer = new Timer(20, new LineListener());
		
		x=0;
		
		setPreferredSize(new Dimension(400, 200));
		timer.start();
	}
	
	public void paintComponent(Graphics g){
		super.paintComponent(g);
		g.drawLine(200, 0, 200, 200);
		g.setColor(Color.blue);
		if(x<200){
			g.drawLine(x, 100, x-75, 100);
		}
		else if(x>275){
			g.setColor(Color.red);
			g.drawLine(x, 100, x-75, 100);
		}
		else{
			g.drawLine(200, 100, x-75, 100);
			g.setColor(Color.red);
			g.drawLine(x, 100, 200, 100);
		}
		
	}
	
	private class LineListener implements ActionListener{
		public void actionPerformed(ActionEvent event){
			x++;
			repaint();
		}
	}
	
	public static void main(String[] args) {
		JFrame frame = new JFrame("Color Line");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		ColorLine panel = new ColorLine();
		frame.getContentPane().add(panel);
		frame.pack();
		frame.setVisible(true);
	}

}
