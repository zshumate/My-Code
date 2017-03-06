
public class Task implements Priority{
	private int priority;
	private String todo;
	
	public Task(String task){
		priority = 0;
		todo = task;
	}
	
	public void setPriority(int priority){
		this.priority = priority;
	}
	
	public int getPriority(){
		return priority;
	}
	
	public String toString(){
		String result;
		
		result = "Task: " + todo + "\n";
		result += "Priority: " + priority + "\n";
		return result;
	}
	

	public static void main(String[] args) {
		Task hmwk = new Task("Do homework");
		hmwk.setPriority(1);
		Task chores = new Task("Do chores");
		chores.setPriority(2);
		Task eat = new Task("Eat");
		
		System.out.println(hmwk);
		System.out.println(chores);
		System.out.println(eat);
	}

}