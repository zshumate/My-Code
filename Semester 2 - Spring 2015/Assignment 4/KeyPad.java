import java.awt.*;
import java.awt.event.*;

import javax.swing.*;


public class KeyPad extends JPanel{
	private JLabel outputLabel;
	private JButton b1, b2, b3, b4, b5, b6, b7, b8, b9, b0, b, clear;
	private JPanel grid;
	
	public KeyPad(){
		setLayout(new BorderLayout());
		
		outputLabel = new JLabel(" ");
		outputLabel.setBorder(BorderFactory.createLineBorder(Color.black));
		
		grid = new JPanel();
		grid.setLayout(new GridLayout(4, 3));
		grid.setBorder(BorderFactory.createLineBorder(Color.black));
		
		b = new JButton();
		b1 = new JButton("1");
		b1.addActionListener(new NumListener());
		b2 = new JButton("2");
		b2.addActionListener(new NumListener());
		b3 = new JButton("3");
		b3.addActionListener(new NumListener());
		b4 = new JButton("4");
		b4.addActionListener(new NumListener());
		b5 = new JButton("5");
		b5.addActionListener(new NumListener());
		b6 = new JButton("6");
		b6.addActionListener(new NumListener());
		b7 = new JButton("7");
		b7.addActionListener(new NumListener());
		b8 = new JButton("8");
		b8.addActionListener(new NumListener());
		b9 = new JButton("9");
		b9.addActionListener(new NumListener());
		b0 = new JButton("0");
		b0.addActionListener(new NumListener());
		
		clear = new JButton("Clear");
		clear.addActionListener(new ClearListener());
		
		grid.add(b1);
		grid.add(b2);
		grid.add(b3);
		grid.add(b4);
		grid.add(b5);
		grid.add(b6);
		grid.add(b7);
		grid.add(b8);
		grid.add(b9);
		grid.add(b);
		grid.add(b0);
		
		add(outputLabel, BorderLayout.NORTH);
		add(grid, BorderLayout.CENTER);
		add(clear, BorderLayout.EAST);
		
		setPreferredSize(new Dimension(250, 200));
	}
	
	private class NumListener implements ActionListener{
		public void actionPerformed(ActionEvent event) {
			String text = outputLabel.getText();
			text += event.getActionCommand();
			outputLabel.setText(text);
		}
		
	}
	
	private class ClearListener implements ActionListener{
		public void actionPerformed(ActionEvent event) {
			outputLabel.setText(" ");
		}
		
	}

	public static void main(String[] args) {
		JFrame frame = new JFrame("Key Pad");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		KeyPad panel = new KeyPad();
		frame.getContentPane().add(panel);
		frame.pack();
		frame.setVisible(true);
	}

}
