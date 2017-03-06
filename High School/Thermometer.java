//Zack Shumate
//AP Java
//Lab 10

public class Thermometer{
	private double degreesCelsius;

	public void setCelsius(double degrees){
		degreesCelsius=degrees;
		return;
	}
	public double getCelsius(){
		return degreesCelsius;
	}
	public void setFahrenheit(double degrees){
		degreesCelsius=(degrees-32.0)*5.0/9.0;
		return;
	}
	public double getFahrenheit(){
			return degreesCelsius*9.0/5.0+32.0;
	}
}