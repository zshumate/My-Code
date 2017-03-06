//Zack Shumate
//AP Java
//Lab 8

public class Property{
	private int cost;
	private int rent;
	private int mortgage;
	private String color;
	private int houses;

	public Property(){
		cost=0;
		rent=0;
		mortgage=0;
		color=" ";
		houses=0;
	}
	public Property(int c, int r,int m, String co, int h){
		cost=c;
		rent=r;
		mortgage=m;
		color=co;
		houses=h;
	}
	public void setCost(int c){
		cost=c;
		return;
	}
	public int getCost(){
		return cost;
	}
	public void setRent(int r){
		rent=r;
		return;
	}
	public int getRent(){
		return rent;
	}
	public int getMortgage(){
		return mortgage;
	}
	public String getColor(){
		return color;
	}
	public void setHouses(int h){
		houses=h;
		return;
	}
	public int getHouses(){
		return houses;
	}
}