import java.awt.*;

public class Terrain {
	int x;
	int y;
	int width;
	int height;
	
	Rectangle hitbox;
	
	public Terrain (int x, int y, int width, int height) {
		this.x = x;
		this.y = y;
		this.width = width;
		this.height = height;
		
		hitbox = new Rectangle(x, y, width, height);
	
	}//constructor
	
	public void draw (Graphics2D g) {
		g.setColor(Color.BLACK);
		g.drawRect(x, y, width, height);
		g.setColor(Color.white);
		g.fillRect(x+1, y+1, width-2, height-2);
		
	}
	
	public static void main (String args[]) {
		
	}
}//Terrain