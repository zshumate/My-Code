import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class FahrenheitPanel extends JPanel{
	private JLabel inputLabel, outputLabel, resultLabel;
	private JTextField fahrenheit;
	private JButton push;
	
	public FahrenheitPanel(){
		inputLabel = new JLabel("Enter Fahrenheit temperature:");
		outputLabel = new JLabel("Temperature in Celcius");
		resultLabel = new JLabel("---");
		
		fahrenheit = new JTextField(5);
		fahrenheit.addActionListener(new TempListener());
		
		push = new JButton("Calculate");
		push.addActionListener(new TempListener());
		
		add(inputLabel);
		add(fahrenheit);
		add(outputLabel);
		add(resultLabel);
		add(push);
		
		setPreferredSize(new Dimension(300, 75));
		setBackground(Color.yellow);
	}
	
	private class TempListener implements ActionListener{
		public void actionPerformed(ActionEvent event) {
			String text = fahrenheit.getText();
			int fahrenheitTemp = Integer.parseInt(text);
			int celsiusTemp = (fahrenheitTemp-32)*5/9;
			resultLabel.setText(Integer.toString(celsiusTemp));
		}
		
	}
}
