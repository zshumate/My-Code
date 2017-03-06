
public class pairOfDice {
	private final int MAX = 6;
	private int faceValue1;
	private int faceValue2;
	
	public pairOfDice(){
		faceValue1 = 1;
		faceValue2 = 1;
	}
	
	public int roll1(){
		faceValue1 = (int)(Math.random()*MAX)+1;
		return faceValue1;
	}
	
	public int roll2(){
		faceValue2 = (int)(Math.random()*MAX)+1;
		return faceValue2;
	}
	
	public void setFaceValue1(int value1){
		faceValue1 = value1;
	}
	
	public void setFaceValue2(int value2){
		faceValue2 = value2;
	}
	
	public int getFaceValue1(){
		return faceValue1;
	}
	
	public int getFaceValue2(){
		return faceValue2;
	}
}
