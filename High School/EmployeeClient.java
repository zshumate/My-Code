//Zack Shumate
//AP Java
//Lab 2

public class EmployeeClient{
	public static void main(String [] args){
		Employee e1=new Employee();
		System.out.println("Employee's last name is "+e1.getLastName());
		System.out.println("Employee's pay rate is $"+e1.getPayRate());
		e1.setLastName("Shumate");
		e1.setPayRate(10.25);
		System.out.println("Employee's last name is "+e1.getLastName());
		System.out.println("Employee's pay rate is $"+e1.getPayRate());

		TechEmployee te1=new TechEmployee();
		System.out.println("\nEmployee's last name is "+te1.getLastName());
		System.out.println("Employee's pay rate is $"+te1.getPayRate());
		System.out.println("Employee's qualifications are "+te1.getQual());
		te1.setLastName("Shumate");
		te1.setPayRate(10.25);
		te1.setQual("forklift driver");
		System.out.println("Employee's last name is "+te1.getLastName());
		System.out.println("Employee's pay rate is $"+te1.getPayRate());
		System.out.println("Employee's qualifications are "+te1.getQual());

		System.out.println("\nThere are "+Employee.getEmployeeCount()+" employees");
	}
}