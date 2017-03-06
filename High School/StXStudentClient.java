//Zack Shumate
//AP Java
//Lab 7

public class StXStudentClient{
	public static void main(String [] args){
		StXStudent s1=new StXStudent();
		System.out.println("The student's name is "+s1.getFirstName()+" "+s1.getLastName());
		System.out.println("The student's student number is "+s1.getStudentNumber());
		System.out.println("The student's GPA is "+s1.getGPA());
		s1.setStudentNumber(11192);
		s1.setLastName("Shumate");
		s1.setFirstName("Zack");
		s1.setGPA(3.49);
		System.out.println("\nThe student's name is "+s1.getFirstName()+" "+s1.getLastName());
		System.out.println("The student's student number is "+s1.getStudentNumber());
		System.out.println("The student's GPA is "+s1.getGPA());
		StXStudent s2=new StXStudent(1234, "Smith", "John", 3.62);
		System.out.println("\nThe student's name is "+s2.getFirstName()+" "+s2.getLastName());
		System.out.println("The student's student number is "+s2.getStudentNumber());
		System.out.println("The student's GPA is "+s2.getGPA());
	}
}