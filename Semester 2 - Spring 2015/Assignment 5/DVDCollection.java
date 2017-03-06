import java.text.NumberFormat;

public class DVDCollection {
	private DVD[] collection;
	private int count;
	private double totalCost;
	
	public DVDCollection(){
		collection = new DVD[100];
		count = 0;
		totalCost = 0.0;
	}
	
	public void addDVD(String title, String director, int year, double cost, boolean bluray){
		collection[count] = new DVD(title,director,year,cost,bluray);
		totalCost +=cost;
		count++;
	}
	
	public void sort(){
		int min;
		DVD temp;
		
		for(int index = 0; index<collection.length-1; index++){
			min = index;
			for(int scan = index+1; scan<collection.length; scan++){
				
			}
		}
	}
	
	public String toString(){
		NumberFormat fmt = NumberFormat.getCurrencyInstance();
		
		String report = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		report += "Number of DVDs: "+count+"\n";
		report += "Total cost: "+fmt.format(totalCost);
		report += "Average cost: "+fmt.format(totalCost/count);
		report += "\n\nDVD List:\n\n";
		for(int dvd = 0; dvd<count; dvd++){
			report += collection[dvd].toString()+"\n";
		}
		return report;
	}
	
	public static void main(String[] args) {
		DVDCollection movies = new DVDCollection();
		
		movies.addDVD("All About Eve", "Joseph Mankiewicz", 1950, 17.50, false);
		movies.addDVD("District 9", "Neill Blomkamp", 2009, 19.95, false);
		movies.addDVD("Iron Man", "Jon Favreau", 2008, 15.95, false);
		movies.addDVD("The Godfather", "Francis Ford Coppola", 1972, 24.95, true);
		movies.addDVD("The Matrix", "Andy & Lana Wachowski", 1999, 19.95, true);
		
		System.out.println(movies);
	}

}
