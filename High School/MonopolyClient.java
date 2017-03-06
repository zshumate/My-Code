//Zack Shumate
//AP Java
//Lab 8

class MonopolyClient{
	public static void main(String [] args){

		//Player class default constructor
		System.out.println("Player class default constructor");
		Player pl1=new Player();
		System.out.println("\nThe player is on tile "+pl1.getPosition());
		System.out.println("The player has $"+pl1.getMoney());
		System.out.println("The player is playing as "+pl1.getToken());
		System.out.println("The player owns "+pl1.getProperties()+" properties");
		System.out.println("The player is in "+pl1.getRank()+" place");
		pl1.setPosition(32);
		pl1.setMoney(500);
		pl1.setProperties(2);
		pl1.setRank(3);
		System.out.println("\nThe player is on tile "+pl1.getPosition());
		System.out.println("The player has $"+pl1.getMoney());
		System.out.println("The player is playing as "+pl1.getToken());
		System.out.println("The player owns "+pl1.getProperties()+" properties");
		System.out.println("The player is in "+pl1.getRank()+" place");

		//Player class second constructor
		System.out.println("\nPlayer class second constructor");
		Player pl2=new Player(12, 1000, "battleship", 4, 2);
		System.out.println("\nThe player is on tile "+pl2.getPosition());
		System.out.println("The player has $"+pl2.getMoney());
		System.out.println("The player is playing as "+pl2.getToken());
		System.out.println("The player owns "+pl2.getProperties()+" properties");
		System.out.println("The player is in "+pl2.getRank()+" place");

		//Property class default constructor
		System.out.println("\nProperty class default constructor");
		Property pr1=new Property();
		System.out.println("\nThe property's cost is $"+pr1.getCost());
		System.out.println("The property's rent is $"+pr1.getRent());
		System.out.println("The property's mortgage is $"+pr1.getMortgage());
		System.out.println("The property's color is "+pr1.getColor());
		System.out.println("The property has "+pr1.getHouses()+" houses");
		pr1.setCost(200);
		pr1.setRent(50);
		pr1.setHouses(3);
		System.out.println("\nThe property's cost is $"+pr1.getCost());
		System.out.println("The property's rent is $"+pr1.getRent());
		System.out.println("The property's mortgage is $"+pr1.getMortgage());
		System.out.println("The property's color is "+pr1.getColor());
		System.out.println("The property has "+pr1.getHouses()+" houses");

		//Property class second constructor
		System.out.println("\nProperty class second constructor");
		Property pr2=new Property(750, 200, 150, "red", 1);
		System.out.println("\nThe property's cost is $"+pr2.getCost());
		System.out.println("The property's rent is $"+pr2.getRent());
		System.out.println("The property's mortgage is $"+pr2.getMortgage());
		System.out.println("The property's color is "+pr2.getColor());
		System.out.println("The property has "+pr2.getHouses()+" houses");

		//Card class default constructor
		System.out.println("\nCard class default constructor");
		Card c1=new Card();
		System.out.println("\nThe card is "+c1.getType());
		System.out.println("The card's effect is "+c1.getEffect());
		System.out.println("There are "+c1.getCardsLeft()+" cards left");

		//Card class second constructor
		System.out.println("\nCard class second constructor");
		Card c2=new Card("Chance", "Go to Jail", 15);
		System.out.println("\nThe card is "+c2.getType());
		System.out.println("The card's effect is "+c2.getEffect());
		System.out.println("There are "+c2.getCardsLeft()+" cards left");
	}
}