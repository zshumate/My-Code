
public class Die {

	public static void main(String[] args) {
		Die dice = new Die();
		
		dice.roll();
		System.out.println("Die: " + dice.getFaceValue());
		
		dice.setFaceValue(10);
		dice.setFaceValue(2);
		System.out.println("Die: " + dice.getFaceValue());
	}
	
	private final int MAX = 6;
	private int faceValue;
	
	public Die(){
		faceValue = 1;
	}
	
	public int roll(){
		faceValue = (int)(Math.random()*MAX)+1;
		return faceValue;
	}
	
	public void setFaceValue(int value){
		if(value>=0 && value<=6){
			faceValue = value;
		}
		else{
			System.out.println("Input a number between 1 and 6");
		}
	}
	
	public int getFaceValue(){
		return faceValue;
	}
}
