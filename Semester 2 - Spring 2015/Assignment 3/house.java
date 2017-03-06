import javax.swing.*;
import java.awt.*;

public class house {

	public static void main(String[] args) {
		JFrame theGUI =  new JFrame();
		theGUI.setTitle("House and Fence");
		theGUI.setSize(400, 300);
		theGUI.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		ColorPanel panel = new ColorPanel(Color.white);
		Container pane = theGUI.getContentPane();
		pane.add(panel);
		theGUI.setVisible(true);
	}

}
