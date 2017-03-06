class Client{
	public static void main(String [] args){
		Dog d1=new Dog();
		System.out.println("The breed is "+d1.getBreed());
		d1.setBreed("Spot");
		System.out.println("The breed is "+d1.getBreed());
		Dog d2=new Dog("Beagle", 5, 20);
		System.out.println("The breed is "+d2.getBreed());
		d1.setAge(12);
		System.out.println("The age is "+d1.getAge());
		d1.setHeight(20);
		System.out.println("The height is "+d1.getHeight());
		d1.bark();
	}
}