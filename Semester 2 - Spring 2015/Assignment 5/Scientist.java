
public class Scientist implements Speaker{
	private String phrase;
	
	public Scientist(){
		phrase = "The Earth revolves around the sun";
	}
	
	public void speak(){
		System.out.println(phrase);
	}
	
	public void announce(String str){
		System.out.println(str);
	}
}
