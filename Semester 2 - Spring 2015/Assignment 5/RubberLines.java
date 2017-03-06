import java.awt.*;
import java.awt.event.*;

import javax.swing.*;
import java.util.ArrayList;


public class RubberLines extends JPanel{
	private Point point1 = null, point2 = null;
	private ArrayList<Point> pointList;
	
	public RubberLines(){
		pointList = new ArrayList<Point>();
		
		LineListener listener = new LineListener();
		addMouseListener(listener);
		addMouseMotionListener(listener);
		
		setBackground(Color.black);
		setPreferredSize(new Dimension(400,200));
	}
	
	public void paintComponent(Graphics g){
		super.paintComponent(g);
		g.setColor(Color.yellow);
		for(int i = 0; i<pointList.size(); i+=2){
			g.drawLine(pointList.get(i).x, pointList.get(i).y, pointList.get(i+1).x, pointList.get(i+1).y);
		}
		if(point1 != null && point2 != null){
			g.drawLine(point1.x, point1.y, point2.x, point2.y);
		}
	}
	
	private class LineListener implements MouseListener, MouseMotionListener{
		public void mousePressed(MouseEvent event){
			point1 = event.getPoint();
		}
		public void mouseDragged(MouseEvent event){
			point2 = event.getPoint();
			repaint();
		}
		public void mouseReleased(MouseEvent event) {
			pointList.add(point1);
			pointList.add(point2);
		}
		public void mouseMoved(MouseEvent e) {
			// TODO Auto-generated method stub
			
		}
		public void mouseClicked(MouseEvent e) {
			// TODO Auto-generated method stub
			
		}
		public void mouseEntered(MouseEvent e) {
			// TODO Auto-generated method stub
			
		}
		public void mouseExited(MouseEvent e) {
			// TODO Auto-generated method stub
			
		}	
	}

	public static void main(String[] args) {
		JFrame frame = new JFrame("Rubber Lines");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		RubberLines panel = new RubberLines();
		frame.getContentPane().add(panel);
		frame.pack();
		frame.setVisible(true);
	}

}
