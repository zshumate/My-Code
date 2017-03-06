import java.io.IOException;
import java.util.Scanner;


public class StringTooLong extends IOException{
	
	StringTooLong(){
	}
	
	public static void main(String[] args) throws StringTooLong{
		boolean cont = true;
		Scanner scan = new Scanner(System.in);
		while(cont){
			System.out.println("Enter a string (max 20 characters), when finished enter DONE: ");
			String string = scan.nextLine();
		
			if(string.length()>=20){
				throw new StringTooLong();
			}
			
			if(string.equals("DONE")){
				cont = false;
			}
		}
	}

}
