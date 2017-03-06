import javax.swing.*;
import java.awt.*;
public class NetherlandFlag{
	public static void main(String[] args){
		JFrame theGUI = new JFrame();
		theGUI.setTitle("Netherland's Flag");
		theGUI.setSize(300, 200);
		theGUI.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		JPanel panel1 = new JPanel();
		panel1.setBackground(Color.red);
		JPanel panel2 = new JPanel();
		panel2.setBackground(Color.white);
		JPanel panel3 = new JPanel();
		panel3.setBackground(Color.blue);
		Container pane = theGUI.getContentPane();
		pane.setLayout(new GridLayout(3, 1));
		pane.add(panel1);
		pane.add(panel2);
		pane.add(panel3);
		theGUI.setVisible(true);
	}
}