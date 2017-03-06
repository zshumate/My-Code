import java.util.Scanner;


public class StringTooLongException extends Exception{
	
	StringTooLongException(){
	}
	
	public static void main(String[] args) throws StringTooLongException{
		boolean cont = true;
		Scanner scan = new Scanner(System.in);
		while(cont){
			System.out.println("Enter a string (max 20 characters), when finished enter DONE: ");
			String string = scan.nextLine();
			
			try{
				if(string.length()>=20){
					throw new StringTooLongException();
				}
			}
			catch(StringTooLongException exception){
				System.out.println("String too long.");
			}
			if(string.equals("DONE")){
				cont = false;
			}
		}
	}
}