//Zack Shumate
//AP Java
//Lab 2

public class TechEmployee extends Employee{
	protected String qual;

	public TechEmployee(){
		super();
		qual=" ";
	}
	protected void setQual(String ql){
		qual=ql;
		return;
	}
	protected String getQual(){
		return qual;
	}
	protected void setPayRate(double pr){
		payRate=pr*2;
		return;
	}
}