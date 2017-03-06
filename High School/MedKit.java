//Zack Shumate
//AP Java
//Test 3

public class MedKit{
	private int height;
	private int width;
	private int depth;
	private String color;
	private Boolean potion;

	public MedKit(){
		height=0;
		width=0;
		depth=0;
		color="white";
		potion=false;
	}

	public void setHeight(int h){
		height=h;
		return;
	}
	public int getHeight(){
		return height;
	}
	public void setWidth(int w){
		width=w;
		return;
	}
	public int getWidth(){
		return width;
	}
	public void setDepth(int d){
		depth=d;
		return;
	}
	public int getDepth(){
		return depth;
	}
	public void setColor(String c){
		color=c;
		return;
	}
	public String getColor(){
		return color;
	}
	public void setPotion(Boolean p){
		potion=p;
		return;
	}
	public Boolean getPotion(){
		return potion;
	}
}