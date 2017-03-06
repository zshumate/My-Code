//Zack Shumate
//AP Java
//Lab 8

public class Card{
	private String type;
	private String effect;
	private int cardsLeft;

	public Card(){
		type=" ";
		effect=" ";
		cardsLeft=16;
	}
	public Card(String t, String e, int cl){
		type=t;
		effect=e;
		cardsLeft=cl;
	}
	public String getType(){
		return type;
	}
	public String getEffect(){
		return effect;
	}
	public int getCardsLeft(){
		return cardsLeft;
	}
}