//Zack Shumate
//AP Java
//Test 3

class MedKitClient{
	public static void main(String [] args){
		MedKit m1=new MedKit();
		System.out.println("The medkit's height is "+m1.getHeight());
		System.out.println("The medkit's width is "+m1.getWidth());
		System.out.println("The medkit's depth is "+m1.getDepth());
		System.out.println("The medkit's color is "+m1.getColor());
		if (m1.getPotion()==true){
			System.out.println("The medkit has a life potion");
		}
		else{
			System.out.println("The medkit does not have a life potion");
		}
		m1.setHeight(2);
		m1.setWidth(3);
		m1.setDepth(4);
		m1.setColor("red");
		m1.setPotion(true);
		System.out.println("\nThe medkit's height is "+m1.getHeight());
		System.out.println("The medkit's width is "+m1.getWidth());
		System.out.println("The medkit's depth is "+m1.getDepth());
		System.out.println("The medkit's color is "+m1.getColor());
		if (m1.getPotion()==true){
			System.out.println("The medkit has a life potion");
		}
		else{
			System.out.println("The medkit does not have a life potion");
		}
	}
}