import java.util.Scanner;
import java.awt.*;
import java.awt.event.*;
import java.io.*;

import javax.swing.*;

public class DisplayFile {
	public static void main(String[] args) throws IOException{
		JFrame frame = new JFrame("Display File");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		JPanel panel = new JPanel();
		JTextArea ta = new JTextArea(20,30);
		JFileChooser chooser = new JFileChooser();
		JButton button = new JButton("Save");
		
		//button.addActionListener(new ButtonListener());
		
		panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS));
		panel.add(button);
		panel.add(ta);
		
		int status = chooser.showOpenDialog(null);
		
		if(status != JFileChooser.APPROVE_OPTION){
			ta.setText("No File Chosen");
		}
		else{
			File file = chooser.getSelectedFile();
			Scanner scan = new Scanner(file);
			
			String info = "";
			while(scan.hasNext()){
				info +=scan.nextLine();
			}
			ta.setText(info);
		}
		
		frame.getContentPane().add(panel);
		frame.pack();
		frame.setVisible(true);
	}
	
	private class ButtonListener implements ActionListener{
		public void actionPerformed(ActionEvent event) {
			
		}
	}
}
