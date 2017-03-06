import java.util.Scanner;

public class vowel {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int a = 0,e = 0,i = 0,o = 0,u = 0;
		
		System.out.println("Enter a Sentece: ");
		String str = scan.nextLine();
		
		for (int x = 0; x < str.length(); x++) {
		    switch(str.charAt(x)) {
		        case 'a':
		        	a++;
		            break;
		        case 'e':
		        	e++;
		            break;
		        case 'i':
		        	i++;
		            break;
		        case 'o':
		        	o++;
		            break;
		        case 'u':
		            u++;
		            break;
		    }
		}
		System.out.println("There are " + a +" a's");
		System.out.println("There are " + e +" e's");
		System.out.println("There are " + i +" i's");
		System.out.println("There are " + o +" o's");
		System.out.println("There are " + u +" u's");
		System.out.println("There are " + (str.length()-(a+e+i+o+u)) +" non-vowels");
	}

}
