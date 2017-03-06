//Zack Shumate
//AP Java
//Lab 7

public class StXStudent{
	private int studentNumber;
	private String lastName;
	private String firstName;
	private double GPA;

	public StXStudent(){
		studentNumber=0000;
		lastName="Doe";
		firstName="John";
		GPA=0.0;
	}
	public StXStudent(int sn, String ln, String fn, double gpa){
		studentNumber=sn;
		lastName=ln;
		firstName=fn;
		GPA=gpa;
	}
	public void setStudentNumber(int sn){
		studentNumber=sn;
		return;
	}
	public int getStudentNumber(){
		return studentNumber;
	}
	public void setLastName(String ln){
			lastName=ln;
		return;
	}
	public String getLastName(){
		return lastName;
	}
	public void setFirstName(String fn){
		firstName=fn;
		return;
	}
	public String getFirstName(){
		return firstName;
	}
	public void setGPA(double gpa){
		GPA=gpa;
		return;
	}
	public double getGPA(){
		return GPA;
	}
}