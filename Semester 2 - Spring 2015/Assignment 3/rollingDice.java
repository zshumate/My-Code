
public class rollingDice {

	public static void main(String[] args) {
		pairOfDice dice = new pairOfDice();
		
		dice.roll1();
		dice.roll2();
		System.out.println("Die One: " + dice.getFaceValue1() + ", Die Two: " + dice.getFaceValue2());
		
		dice.roll1();
		dice.setFaceValue2(4);
		System.out.println("Die One: " + dice.getFaceValue1() + ", Die Two: " + dice.getFaceValue2());
		
		System.out.println("Sum One: " + (dice.getFaceValue1()+dice.getFaceValue2()));
	}

}
