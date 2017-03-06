
public class Student {
	private String firstName, lastName;
	private double test1, test2, test3;
	
	public Student(String first, String last, double t1, double t2, double t3){
		firstName = first;
		lastName = last;
		test1 = t1;
		test2 = t2;
		test3 = t3;
	}
	
	public Student(String first, String last){
		firstName = first;
		lastName = last;
		test1 = 0;
		test2 = 0;
		test3 = 0;
	}
	
	public void setTestScore(int test, double score){
		if(test == 1){
			test1 = score;
		}
		else if(test == 2){
			test2 = score;
		}
		else if(test == 3){
			test3 = score;
		}
		else{
			System.out.println("Input proper test number.");
		}
	}
	
	public double getTestScore(int test){
		double score = 0;
		
		if(test == 1){
			score = test1;
		}
		else if(test == 2){
			score = test2;
		}
		else if(test == 3){
			score = test3;
		}
		else{
			System.out.println("Input proper test number.");
		}
		
		return score;
	}
	
	public double average(){
		return ((test1+test2+test3)/3);
	}
	
	public String toString(){
		String result;
		
		result = firstName + " " + lastName;
		return result;
	}
}
