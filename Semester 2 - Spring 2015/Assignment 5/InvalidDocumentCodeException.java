import java.util.Scanner;


public class InvalidDocumentCodeException extends Exception{

	InvalidDocumentCodeException(){
	}
	
	public static void main(String[] args) throws InvalidDocumentCodeException{
		System.out.println("Input a document designation (U for unclassified, C for confidential, or P for proprietary): ");
		Scanner scan = new Scanner(System.in);
		
		String doc = scan.nextLine();
		
		try{
			if(!doc.equals("U")&&!doc.equals("C")&&!doc.equals("P")){
				throw new InvalidDocumentCodeException();
			}
		}
		catch(InvalidDocumentCodeException exception){
			System.out.println("Improper designation.");
		}
		
		System.out.println("Complete");
	}
}
