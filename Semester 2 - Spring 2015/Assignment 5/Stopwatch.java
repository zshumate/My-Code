import java.awt.*;
import java.awt.event.*;

import javax.swing.*;

public class Stopwatch extends JPanel{
	private Timer timer;
	private int time;
	private JLabel outputLabel;
	private JButton start, stop, reset;
	
	public Stopwatch(){
		setLayout(new BoxLayout(this, BoxLayout.Y_AXIS));
		
		timer = new Timer(1000, new timeListener());
		time = 0;
		
		outputLabel = new JLabel("0");
		
		start = new JButton("Start");
		start.addActionListener(new startListener());
		stop = new JButton("Stop");
		stop.addActionListener(new stopListener());
		reset = new JButton("Reset");
		reset.addActionListener(new resetListener());
		
		add(outputLabel);
		add(start);
		add(stop);
		add(reset);
		
		setPreferredSize(new Dimension(20, 100));
	}
	
	private class timeListener implements ActionListener{
		public void actionPerformed(ActionEvent event){
			time++;
			outputLabel.setText(""+time);
		}
	}
	
	private class startListener implements ActionListener{
		public void actionPerformed(ActionEvent event){
			timer.start();
		}
	}
	
	private class stopListener implements ActionListener{
		public void actionPerformed(ActionEvent event){
			timer.stop();
		}
	}
	
	private class resetListener implements ActionListener{
		public void actionPerformed(ActionEvent event){
			time = 0;
			outputLabel.setText(""+time);
		}
	}

	public static void main(String[] args) {
		JFrame frame = new JFrame("Stopwatch");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Stopwatch panel = new Stopwatch();
		frame.getContentPane().add(panel);
		frame.pack();
		frame.setVisible(true);
	}

}
