//ProgrammingPT
//Zack Shumate


import java.io.*;
import java.util.ArrayList;
import javax.swing.*;
import javax.swing.filechooser.FileNameExtensionFilter;
import javax.swing.text.BadLocationException;
import java.awt.*;
import java.awt.event.*;

public class WordSearchGUI extends JFrame{
	public static void main(String [] args){
		windowSwap(true, null, null);
	}

	//swaps the GUI screens
	public static void windowSwap(Boolean b, String s, String w){
		WordSearchGUI window1 = new WordSearchGUI(true, null, null);
		//file search screen
		if(b == true){
			window1.setTitle("Word Search");
			window1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			window1.pack();
			window1.setVisible(true);
		}
		//result display screen
		else if(b == false){
			WordSearchGUI window2 = new WordSearchGUI(false, s, w);
			window2.setTitle("Word Search");
			window2.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			window2.pack();
			window1.setVisible(false);
			window2.setVisible(true);
			window2.setSize(1200, 700);
		}
	}

	private JLabel fileLabel = new JLabel("Select file:");
	private JTextField fileField = new JTextField("");
	private JButton fileButton = new JButton("Browse...");
	private JButton searchButton = new JButton("Search");

	private JTextArea fileArea = new JTextArea(40, 75);
	private JScrollPane filePane = new JScrollPane(fileArea);
	private JTextArea wordsArea = new JTextArea(40, 25);
	private JScrollPane wordsPane = new JScrollPane(wordsArea);

	public WordSearchGUI(Boolean b, String s, String w){
		//file search screen
		if(b == true){
			Container container1 = getContentPane();
			container1.setLayout(new BoxLayout(container1, BoxLayout.Y_AXIS));
			JPanel filePanel = new JPanel(new GridLayout(1, 3));
			filePanel.add(fileLabel);
			filePanel.add(fileField);
			filePanel.add(fileButton);
			container1.add(filePanel);
			JPanel buttonPanel = new JPanel();
			buttonPanel.add(searchButton);
			container1.add(buttonPanel);
			fileButton.addActionListener(new FileBrowseListener());
			searchButton.addActionListener(new SearchListener());
		}
		//result display screen
		else if(b == false){
			JTextArea fileArea = new JTextArea(s, 40, 75);
			JScrollPane filePane = new JScrollPane(fileArea);
			JTextArea wordsArea = new JTextArea(w, 40, 25);
			JScrollPane wordsPane = new JScrollPane(wordsArea);

			fileArea.setLineWrap(true);
			fileArea.setWrapStyleWord(true);
			fileArea.setEditable(false);
			wordsArea.setLineWrap(true);
			wordsArea.setWrapStyleWord(true);
			wordsArea.setEditable(false);
			Container container2 = getContentPane();
			JPanel fileAreaPanel = new JPanel();
			fileAreaPanel.add(filePane);
			container2.add(fileAreaPanel, BorderLayout.WEST);
			JPanel wordAreaPanel = new JPanel();
			wordAreaPanel.add(wordsPane);
			container2.add(wordAreaPanel, BorderLayout.EAST);
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

	private class SearchListener implements ActionListener{
		public void actionPerformed(ActionEvent e){
			ArrayList<String> text = new ArrayList<String>();
			ArrayList<String> words = new ArrayList<String>();
			ArrayList<Integer> wordCount = new ArrayList<Integer>();
			String line;
			String fileText = "";
			String wordText = "";

			try{
				String[] split;

				BufferedReader in = new BufferedReader(new FileReader(fileField.getText()));
				while ((line = in.readLine()) != null) {
					// process the line.
					split = line.replaceAll("[^a-zA-Z ]", "").toLowerCase().split("\\s+");
					for (int i=0; i<split.length; i++){
						text.add((split[i]).toLowerCase());
					}
					fileText = fileText.concat(line);
				}
				in.close();

				//count the words
				for(String word:text){
					if(words.contains(word)){
						int j = words.indexOf(word);
						wordCount.set(j, wordCount.get(j)+1);
					}
					else{
						words.add(word);
						wordCount.add(1);
					}
				}

				//sort the occurrence of words in the text
				selectionSort(wordCount, words);

				for(int i=0; i<words.size(); i++){
					wordText = wordText.concat(words.get(i)+" - "+wordCount.get(i)+"\n");
				}
				windowSwap(false, fileText, wordText);
			}

			catch(FileNotFoundException fnfe){
				System.out.println(fnfe.getMessage());
			}

			catch(IOException ioe){
				System.out.println(ioe.getMessage());
			}
		}
	}

	public static void selectionSort(ArrayList<Integer> x, ArrayList<String> y) {
	    for (int i=0; i<x.size()-1; i++) {
	        for (int j=i+1; j<x.size(); j++) {
	            if (x.get(i)<(x.get(j))) {
	                //... Exchange elements in first array
	                int temp = x.get(i);
	                x.set(i, x.get(j));
	                x.set(j, temp);

	                //... Exchange elements in second array
	                String temp2 = y.get(i);
	                y.set(i, y.get(j));
	                y.set(j, temp2);
	            }
	        }
		}
    }
}