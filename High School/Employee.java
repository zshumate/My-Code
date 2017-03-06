//Zack Shumate
//AP Java
//Lab 2

public class Employee{
	protected String lastName;
	protected double payRate;
	protected static int employeeCount=0;

	public Employee(){
		lastName=" ";
		payRate=0;
		employeeCount++;
	}

	protected static int getEmployeeCount(){
		return employeeCount;
	}
	protected void setLastName(String nm){
		lastName=nm;
		return;
	}
	protected String getLastName(){
		return lastName;
	}
	protected void setPayRate(double pr){
		payRate=pr;
		return;
	}
	protected double getPayRate(){
		return payRate;
	}
}