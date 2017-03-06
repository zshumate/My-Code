public class Year{
	public static void main(String [] args){
		double year;
		double day;
		double hour;
		double minute;
		year = 1.00;
		day = year * 365.25;
		hour = day * 24.0;
		minute = hour * 60.0;
		System.out.print("The number of minutes in a year is ");
		System.out.println(minute);
	}
}