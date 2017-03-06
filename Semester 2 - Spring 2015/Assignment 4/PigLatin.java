import java.awt.*;
import java.awt.event.*;
import javax.swing.*;


public class PigLatin extends JPanel{
	private JLabel inputLabel, outputLabel;
	private JTextField input;
	private JButton push;
	
	public PigLatin(){
		setLayout(new BoxLayout(this, BoxLayout.Y_AXIS));
		
		inputLabel = new JLabel("Enter a sentence (no punctuation):");
		outputLabel = new JLabel("---");
		
		input = new JTextField();
		
		push = new JButton("Translate");
		push.addActionListener(new WordListener());
		
		add(inputLabel);
		add(input);
		add(push);
		add(outputLabel);
		
		setPreferredSize(new Dimension(350, 100));
	}
	
	private class WordListener implements ActionListener{
		public void actionPerformed(ActionEvent event) {
			String text = input.getText();
			outputLabel.setText(PigLatinTranslator.translate(text));
		}
		
	}
	

	public static void main(String[] args) {
		JFrame frame = new JFrame("Pig Latin");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		PigLatin panel = new PigLatin();
		frame.getContentPane().add(panel);
		frame.pack();
		frame.setVisible(true);
	}

}
