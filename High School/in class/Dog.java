public class Dog{
	private String breed;
	private int age;
	private int height;

	public Dog(){
		breed="Mutt";
		age=0;
		height=0;
	}
	public Dog(String brd, int ag, int ht){
		breed=brd;
		age=ag;
		height=ht;
	}
	public void setBreed(String br){
		breed=br;
		return;
	}
	public String getBreed(){
		return breed;
	}
	public void setAge(int ag){
			age=ag;
			return;
		}
	public int getAge(){
			return age;
	}
	public void setHeight(int ht){
			height=ht;
			return;
		}
	public int getHeight(){
			return height;
	}
	public void bark(){
		System.out.println("Woof woof");
	}
}