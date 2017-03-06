
public class SpeakerClient {

	public static void main(String[] args) {
		Speaker current = new Philosopher();
		current.speak();
		current = new Dog();
		current.speak();
		current = new Scientist();
		current.announce("Water is wet.");
	}

}
