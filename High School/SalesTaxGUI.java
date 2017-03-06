//Zack Shumate
//AP Java
//Lab 10

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class SalesTaxGUI extends JApplet{
	private SalesTax st=new SalesTax();
	private JLabel costLabel=new JLabel("Cost");
	private JLabel salesTaxLabel=new JLabel("Sales Tax");
	private JLabel totalCostLabel=new JLabel("Total Cost");
	private JTextField costField=new JTextField("0.0");
	private JTextField totalCostField=new JTextField("0.0");
	private JButton salesTaxButton=new JButton("+5%");

	public void init(){
		JPanel dataPanel=new JPanel(new GridLayout(1, 2, 12, 6));
		dataPanel.add(costLabel);
		dataPanel.add(costField);
		JPanel buttonPanel=new JPanel(new GridLayout(1, 2, 12, 6));
		buttonPanel.add(salesTaxLabel);
		buttonPanel.add(salesTaxButton);
		JPanel dataPanel2=new JPanel(new GridLayout(1, 2, 12, 6));
		dataPanel2.add(totalCostLabel);
		dataPanel2.add(totalCostField);
		Container container=getContentPane();
		container.add(dataPanel, BorderLayout.NORTH);
		container.add(buttonPanel, BorderLayout.CENTER);
		container.add(dataPanel2, BorderLayout.SOUTH);
		salesTaxButton.addActionListener(new TaxListener());
	}
	private class TaxListener implements ActionListener{
		public void actionPerformed(ActionEvent e){
			String input=costField.getText();
			double cost=Double.parseDouble(input);
			st.setCost(cost);
			double totalCost=st.getTotalCost();
			totalCostField.setText(""+totalCost);
		}
	}
}