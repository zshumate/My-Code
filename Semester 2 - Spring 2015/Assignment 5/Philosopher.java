
public class Philosopher implements Speaker{
	private String phrase;
	
	public Philosopher(){
		phrase = "What is the meaning of life?";
	}
	
	public void speak(){
		System.out.println(phrase);
	}
	
	public void announce(String str){
		System.out.println(str);
	}
}
