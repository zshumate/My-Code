
public class Dog implements Speaker{
	private String phrase;
	
	public Dog(){
		phrase = "Woof";
	}
	
	public void speak(){
		System.out.println(phrase);
	}
	
	public void announce(String str){
		System.out.println(str);
	}
}
