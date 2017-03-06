//Zack Shumate
//AP Java
//Lab 12

class Name{
	public static void main(String [] args){
		String [] array=new String [1000];
		for(int x=0; x<1000; x++){
			array[x]="Zack Shumate";
		}
		System.out.println("Cell 455 contains "+array[455]);
		System.out.println("Cell 900 contains "+array[900]);
	}
}