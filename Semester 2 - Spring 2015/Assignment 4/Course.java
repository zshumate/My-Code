
public class Course {
	private String courseName;
	private Student[] students;
	private int numStudents;
	
	public Course(String name){
			courseName = name;
			students = new Student[5];
			numStudents = 0;
		}
	
	public void addStudent(Student john){
		students[numStudents] = john;
		numStudents++;
	}
	
	public double average(){
		double average = 0;
		for(Student s:students){
			average += s.average();
		}
		return (average/numStudents);
	}
	
	public void roll(){
		for(Student s:students){
			System.out.println(s);
		}
	}
	
	
	public static void main(String[] args) {
		Student John = new Student("John", "Doe");
		John.setTestScore(1, 97);
		John.setTestScore(2, 79);
		John.setTestScore(3, 82);
		Student Jill = new Student("Jill", "Jones", 77, 89, 78);
		Student Bill = new Student("Bill", "Jones", 87, 93, 90);
		Student Bob = new Student("Bob", "Smith", 70, 75, 82);
		Student Joel = new Student("Joel", "Johnson", 88, 89, 77);
		
		Course math = new Course("Calculus 1");
		math.addStudent(John);
		math.addStudent(Jill);
		math.addStudent(Bill);
		math.addStudent(Bob);
		math.addStudent(Joel);
		math.roll();
		System.out.println("Average grade: " + math.average());
	}	
}
