import java.awt.*;
import java.awt.event.*;

import javax.swing.*;


public class StatPanel extends JPanel{
	public static void main(String[] args) {
		JFrame frame = new JFrame("Basic Statistics");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		StatPanel panel = new StatPanel();
		frame.getContentPane().add(panel);
		frame.pack();
		frame.setVisible(true);
	}
	
	JTextArea text;
	JTextField words;
	JTextField average;
	
	public StatPanel(){
		text = new JTextArea(5, 25);
		text.setLineWrap(true);
		
		JScrollPane sp = new JScrollPane(text);
		
		JLabel wordsLabel = new JLabel("Word Count:");
		JLabel averageLabel = new JLabel("Average Word Length:");
		
		words = new JTextField();
		average = new JTextField();
		
		JButton b = new JButton("Recalculate");
		b.addActionListener(new WordListener());
		
		JPanel pane = new JPanel(new GridLayout(4, 1));
		JPanel miniPane1 = new JPanel(new GridLayout(2, 1));
		JPanel miniPane2 = new JPanel(new GridLayout(2, 1));
		
		miniPane1.add(wordsLabel);
		miniPane1.add(words);
		miniPane2.add(averageLabel);
		miniPane2.add(average);
		
		pane.add(sp);
		pane.add(miniPane1);
		pane.add(miniPane2);
		pane.add(b);
		
		add(pane);
		
		setPreferredSize(new Dimension(300, 350));
	}
	
	private class WordListener implements ActionListener{
		public void actionPerformed(ActionEvent event) {
			String words = text.getText();
			
		}
		
	}
}
