import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.Rectangle;

public class Player {
	GamePanel panel;
	int x;
	int y;
	int width;
	int height;
	
	double xspeed;
	double yspeed;
	double xMaxSpeed = 7;
	double yMaxSpeed;
	double fallSpeed = 0.7;
	double jumpHeight = -12;
	public final static int WIDTH = 26;
	public final static int HEIGHT = 32;
	public final static int CENTER_X = WIDTH/2;
	public final static int CENTER_Y = HEIGHT/2;
	
	Rectangle hitBox;
	
	boolean leftPressed = false;
	boolean rightPressed = false;
	boolean upPressed = false;
	boolean downPressed = false;
	
	protected Sprite sprite; // this entity's sprite
	protected Sprite sprite2; // this entity's flipped sprite
	boolean flipped = false;
	
	public Player (int x, int y, GamePanel panel) {
		this.panel = panel;
		this.x = x;
		this.y = y;
		sprite = (SpriteStore.get()).getSprite("sprites/Woodcutter.png");
		sprite2 = (SpriteStore.get()).getSprite("sprites/Woodcutter2.png");
		width = sprite.getWidth()-8;
		height = sprite.getHeight();
		
		hitBox = new Rectangle(x+4, y, width, height);
		
	}
	
	public void set () {
		/*Movement in x direction*/
		if (leftPressed && rightPressed || !leftPressed && !rightPressed) {
			xspeed *= 0.8;
		} else if (leftPressed && !rightPressed) {
			xspeed--;
			flipped = true;
		} else if (!leftPressed && rightPressed) {
			xspeed++;
			flipped = false;
		}
		if (xspeed > 0 && xspeed < 0.75 || xspeed < 0 && xspeed > -0.75) {
			xspeed = 0;
		}
		if (xspeed > xMaxSpeed) {
			xspeed = xMaxSpeed;
		}
		if (xspeed < xMaxSpeed*-1) {
			xspeed = xMaxSpeed*-1;
		}
		
		/*Movement in y direction*/
		if (upPressed) {
			
			hitBox.y++;
			for (Wall wall: panel.walls) {
				if (wall.hitBox.intersects(hitBox)) {
					yspeed = jumpHeight;
				}
			}
			hitBox.y--;
		}
		yspeed += fallSpeed;
		
		// Horizontal Collision
		hitBox.x += xspeed;
		for (Wall w: panel.walls) {
			if (hitBox.intersects(w.hitBox)) {
				hitBox.x -= xspeed;
				while (!w.hitBox.intersects(hitBox)) {
					hitBox.x += Math.signum(xspeed);
				}
				hitBox.x -= Math.signum(xspeed);
				xspeed = 0;
				x = hitBox.x;
			}
		}
		
		// Vertical Collision
		hitBox.y += yspeed;
		for (Wall w: panel.walls) {
			if (hitBox.intersects(w.hitBox)) {
				hitBox.y -= yspeed;
				while (!w.hitBox.intersects(hitBox)) {
					hitBox.y += Math.signum(yspeed);
				}
				hitBox.y -= Math.signum(yspeed);
				yspeed = 0;
				y = hitBox.y;
			}
		}
		
		panel.cameraX -= xspeed;
		y += yspeed;
		
		hitBox.x = x;
		hitBox.y = y;
	}
	
	public void draw (Graphics2D gtd) {
		if (flipped == true) {
			sprite2.draw(gtd, x-6, y);
		} else {
			sprite.draw(gtd, x, y);
		}
	}
}
