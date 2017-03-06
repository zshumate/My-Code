//Zack Shumate
//AP Java
//Lab 10

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class ThermometerGUI extends JFrame{
	private Thermometer thermo=new Thermometer();
	private JLabel fahrLabel=new JLabel("Degrees Fahrenheit");
	private JLabel celsiusLabel=new JLabel("Degrees Celsius");
	private JTextField fahrField=new JTextField("32.0");
	private JTextField celsiusField=new JTextField("0.0");
	private JButton fahrButton=new JButton("Convert >>>");

	public ThermometerGUI(){
		JPanel dataPanel=new JPanel(new GridLayout(2, 2, 12, 6));
		dataPanel.add(fahrLabel);
		dataPanel.add(celsiusLabel);
		dataPanel.add(fahrField);
		dataPanel.add(celsiusField);
		JPanel buttonPanel=new JPanel();
		buttonPanel.add(fahrButton);
		Container container=getContentPane();
		container.add(dataPanel, BorderLayout.CENTER);
		container.add(buttonPanel, BorderLayout.SOUTH);
		fahrButton.addActionListener(new FahrenheitListener());
	}
	private class FahrenheitListener implements ActionListener{
		public void actionPerformed(ActionEvent e){
			String input=fahrField.getText();
			double fahr=Double.parseDouble(input);
			thermo.setFahrenheit(fahr);
			double celsius=thermo.getCelsius();
			celsiusField.setText(""+celsius);
		}
	}
}