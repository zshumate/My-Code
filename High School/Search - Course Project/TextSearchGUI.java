//ProgrammingPT
//Zack Shumate and Michael Doheny


import java.io.*;
import java.util.ArrayList;
import javax.swing.*;
import javax.swing.filechooser.FileNameExtensionFilter;
import javax.swing.text.BadLocationException;
import javax.swing.text.DefaultHighlighter;
import javax.swing.text.Highlighter;
import javax.swing.text.BadLocationException;
import java.awt.*;
import java.awt.event.*;
import java.awt.Color;

public class TextSearchGUI extends JFrame{
	public static void main(String [] args){
		windowSwap(true, null, null, null);
	}

	//swaps the GUI screens
	public static void windowSwap(Boolean b, String s, String k, ArrayList<String> keywords){
		TextSearchGUI window1 = new TextSearchGUI(true, null, null, null);
		//file search screen
		if(b == true){
			window1.setTitle("Text Search");
			window1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			window1.pack();
			window1.setVisible(true);
		}
		//result display screen
		else if(b == false){
			TextSearchGUI window2 = new TextSearchGUI(false, s, k, keywords);
			window2.setTitle("Text Search");
			window2.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			window2.pack();
			window1.setVisible(false);
			window2.setVisible(true);
			window2.setSize(1200, 700);
		}
	}

	private JLabel fileLabel = new JLabel("Select file:");
	private JLabel keywordLabel = new JLabel("Select keyword file:");
	private JLabel additionalKeywordsLabel = new JLabel("Additional keywords:");
	private JTextField fileField = new JTextField("");
	private JTextField keywordField = new JTextField("");
	private JTextArea additionalKeywordsArea = new JTextArea(5, 10);
	private JScrollPane additionalKeywordsPane = new JScrollPane(additionalKeywordsArea);
	private JButton fileButton = new JButton("Browse...");
	private JButton keywordButton = new JButton("Browse...");
	private JButton searchButton = new JButton("Search");

	private JTextArea fileArea = new JTextArea(40, 75);
	private JScrollPane filePane = new JScrollPane(fileArea);
	private JTextArea keywordsArea = new JTextArea(40, 25);
	private JScrollPane keywordsPane = new JScrollPane(keywordsArea);

	public TextSearchGUI(Boolean b, String s, String k, ArrayList<String> keywords){
		//file search screen
		if(b == true){
			additionalKeywordsArea.setLineWrap(true);
			additionalKeywordsArea.setWrapStyleWord(true);
			Container container1 = getContentPane();
			container1.setLayout(new BoxLayout(container1, BoxLayout.Y_AXIS));
			JPanel filePanel = new JPanel(new GridLayout(1, 3));
			filePanel.add(fileLabel);
			filePanel.add(fileField);
			filePanel.add(fileButton);
			container1.add(filePanel);
			JPanel keywordPanel = new JPanel(new GridLayout(1, 3));
			keywordPanel.add(keywordLabel);
			keywordPanel.add(keywordField);
			keywordPanel.add(keywordButton);
			container1.add(keywordPanel);
			JPanel additionalKeywordsPanel = new JPanel(new GridLayout(1, 2));
			additionalKeywordsPanel.add(additionalKeywordsLabel);
			additionalKeywordsPanel.add(additionalKeywordsPane);
			container1.add(additionalKeywordsPanel);
			JPanel buttonPanel = new JPanel();
			buttonPanel.add(searchButton);
			container1.add(buttonPanel);
			fileButton.addActionListener(new FileBrowseListener());
			keywordButton.addActionListener(new KeywordBrowseListener());
			searchButton.addActionListener(new SearchListener());
		}
		//result display screen
		else if(b == false){
			JTextArea fileArea = new JTextArea(s, 40, 75);
			JScrollPane filePane = new JScrollPane(fileArea);
			JTextArea keywordsArea = new JTextArea(k, 40, 25);
			JScrollPane keywordsPane = new JScrollPane(keywordsArea);

			fileArea.setLineWrap(true);
			fileArea.setWrapStyleWord(true);
			fileArea.setEditable(false);
			highlight(fileArea, keywords);
			keywordsArea.setLineWrap(true);
			keywordsArea.setWrapStyleWord(true);
			keywordsArea.setEditable(false);
			Container container2 = getContentPane();
			JPanel fileAreaPanel = new JPanel();
			fileAreaPanel.add(filePane);
			container2.add(fileAreaPanel, BorderLayout.WEST);
			JPanel keywordAreaPanel = new JPanel();
			keywordAreaPanel.add(keywordsPane);
			container2.add(keywordAreaPanel, BorderLayout.EAST);
		}
	}

	//highlight keywords
	public void highlight(JTextArea a, ArrayList<String> keywords){
		DefaultHighlighter.DefaultHighlightPainter highlightPainter = new DefaultHighlighter.DefaultHighlightPainter(Color.YELLOW);
		Highlighter h = a.getHighlighter();
		h.removeAllHighlights();
		String text = a.getText();
		try{
			for(String keyword:keywords){
				int position = 0;
				position = text.indexOf(keyword, position);
				while(position >= 0){
					h.addHighlight(position, position+keyword.length(), highlightPainter);
					position += keyword.length();
					position = text.indexOf(keyword, position);
				}
			}
		}
		catch(BadLocationException e){
		}
	}

	//search for file
	private class FileBrowseListener implements ActionListener{
		public void actionPerformed(ActionEvent e){
			JFileChooser chooser = new JFileChooser();
			FileNameExtensionFilter filter = new FileNameExtensionFilter("Text File", "txt");
			chooser.setFileFilter(filter);
			int returnVal = chooser.showOpenDialog(new JWindow());
			if(returnVal == JFileChooser.APPROVE_OPTION){
				fileField.setText((chooser.getSelectedFile()).getAbsolutePath());
			}
		}
	}

	//search for keyword file
	private class KeywordBrowseListener implements ActionListener{
		public void actionPerformed(ActionEvent e){
			JFileChooser chooser = new JFileChooser();
			FileNameExtensionFilter filter = new FileNameExtensionFilter("Text File", "txt");
			chooser.setFileFilter(filter);
			int returnVal = chooser.showOpenDialog(new JWindow());
			if(returnVal == JFileChooser.APPROVE_OPTION){
				keywordField.setText((chooser.getSelectedFile()).getAbsolutePath());
			}
		}
	}

	//searches text for keywords
	private class SearchListener implements ActionListener{
		public void actionPerformed(ActionEvent e){
			ArrayList<String> words = new ArrayList<String>();
			ArrayList<String> keywords = new ArrayList<String>();
			ArrayList<Integer> keywordCount = new ArrayList<Integer>();
			String line;
			String fileText = "";
			String keywordText = "";

			try{
				String[] split;

				BufferedReader in2 = new BufferedReader(new FileReader(keywordField.getText()));
				while ((line = in2.readLine()) != null) {
					// process the line.
					split = line.split(" ");
					for (int i=0; i<split.length; i++){
						keywords.add(split[i]);
					}
				}
				line = additionalKeywordsArea.getText();
				if(line.length() > 1){
					split = line.split(" ");
					for (int i=0; i<split.length; i++){
						keywords.add(split[i]);
					}
				}
				in2.close();

				BufferedReader in = new BufferedReader(new FileReader(fileField.getText()));
				while ((line = in.readLine()) != null) {
					// process the line.
					split = line.split(" ");
					for (int i=0; i<split.length; i++){
						words.add(split[i]);
					}
					fileText = fileText.concat(line);
				}
				in.close();

				for(int i=0; i<keywords.size(); i++){
					int number = 0;
					for(String temp:words){
						if((temp.toLowerCase()).contains((keywords.get(i)).toLowerCase())){
							number++;
						}
					}
					keywordCount.add(number);
					keywordText = keywordText.concat(keywords.get(i)+" - "+keywordCount.get(i)+"\n");
				}
				windowSwap(false, fileText, keywordText, keywords);
			}

			catch(FileNotFoundException fnfe){
				System.out.println(fnfe.getMessage());
			}

			catch(IOException ioe){
				System.out.println(ioe.getMessage());
			}
		}
	}
}