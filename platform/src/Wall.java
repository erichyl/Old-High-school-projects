import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.Rectangle;

public class Wall {
	int x;
	int y;
	int startX;
	int width;
	int height;
	
	protected Sprite sprite; // this entity's sprite
	
	Rectangle hitBox;
	
	public Wall (int x, int y, String s) {
		this.x = x;
		startX = x;
		this.y = y;
		sprite = (SpriteStore.get()).getSprite(s);
		width = sprite.getWidth();
		height = sprite.getHeight();
		
		hitBox = new Rectangle(x, y, width, height);
	}
	
	public void draw (Graphics2D gtd) {
		sprite.draw(gtd, x, y);
	}
	
	public int set (int cameraX) {
		x = startX + cameraX;
		hitBox.x = x;
		return x;
	}
	
}
