//Zack Shumate
//AP Java
//Lab 10

public class SalesTax{
	private double cost;

	public void setCost(double c){
		cost=c;
		return;
	}
	public double getCost(){
		return cost;
	}
	public void setTotalCost(double c){
		cost=cost-(cost*.05);
		return;
	}
	public double getTotalCost(){
			return cost+(cost*.05);
	}
}