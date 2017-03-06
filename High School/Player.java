//Zack Shumate
//AP Java
//Lab 8

public class Player{
	private int position;
	private int money;
	private String token;
	private int properties;
	private int rank;

	public Player(){
		position=0;
		money=1500;
		token=" ";
		properties=0;
		rank=0;
	}
	public Player(int pos, int m,String t, int prop, int r){
		position=pos;
		money=m;
		token=t;
		properties=prop;
		rank=r;
	}
	public void setPosition(int pos){
		position=pos;
		return;
	}
	public int getPosition(){
		return position;
	}
	public void setMoney(int m){
		money=m;
		return;
	}
	public int getMoney(){
		return money;
	}
	public String getToken(){
			return token;
	}
	public void setProperties(int prop){
		properties=prop;
		return;
	}
	public int getProperties(){
		return properties;
	}
	public void setRank(int r){
		rank=r;
		return;
	}
	public int getRank(){
		return rank;
	}
}