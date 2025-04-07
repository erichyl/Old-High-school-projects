import java.awt.Graphics2D;
import java.awt.Rectangle;
import java.awt.*;
import java.awt.geom.AffineTransform;
import java.awt.image.BufferedImage;
import java.util.Timer;
import java.util.TimerTask;

import org.w3c.dom.css.Rect;

public class Boss {
	int x;
	int y;
	int movedX;
	int startX;
	int width;
	int height;
	protected double xspeed;
	protected double yspeed;
	private static final int WIDTH = 50;
	private static final int HEIGHT = 25;
	private static final int CENTER_X = WIDTH/2;
	private static final int CENTER_Y = HEIGHT/2;
	
	
	private double slowRate = 10;
	private double xslow;
	private double yslow;
	private double deg = 0;
	private int time = 0;
	private static final double GRAVITY = 0.7;
	
	private int health = 5;
	private boolean collision = true;
	private boolean gravEnabled = true;
	double xMaxSpeed = 7;
	double yMaxSpeed;
	GamePanel panel;
	
	protected Sprite sprite; // this entity's sprite
	
	Rectangle hitBox;
	public Boss (int x, int y, String s, GamePanel panel) {
		this.panel = panel;
		this.x = x;
		startX = x;
		movedX = x;
		this.y = y;
		sprite = (SpriteStore.get()).getSprite(s);
		width = sprite.getWidth();
		height = sprite.getHeight();
		xspeed = 5;
		hitBox = new Rectangle(x, y, width, height);
	}
	public void attackSequence() {
		Timer t1 = new Timer();
		TimerTask tripleDash = new TimerTask() {
			int counter = 0;
			int px;
			int py;
			public void run() {
				gravEnabled = false;
				collision = false;
				px = panel.player.x + Player.CENTER_X;
				py = panel.player.y + Player.CENTER_Y;
				
				Rectangle rect = new Rectangle(px, py, 2, 2);
				
				
				dashTowards(px, py, 40);
				counter++;
				if (counter >= 99) {
					t1.cancel();
				}//if
				
				
			}//run() 
		};//TimerTask tripleDash
		
		Timer t2 = new Timer();
		TimerTask sweepGround = new TimerTask() {

			public void run() {
				Boss.this.x = 700;
				Boss.this.y = 400;
				Timer t = new Timer();
				TimerTask task = new TimerTask() {
					public void run() {
						dash(-60,0);
					} };
				t.schedule(task, 500);
				
			}//run()
			
		};//TimerTask sweepGround
		
		Timer t3 = new Timer();
		TimerTask goCenter = new TimerTask() {

			public void run() {
				Boss.this.x = 400;
				Boss.this.y = 200;
				gravEnabled = true;
				collision = true;
				//dashTo(400,200,50);
				
			}//run
			
		};//timerTask
		
		//time += timer delay + task interal delay + interval*repeats(internal)
		t1.schedule(tripleDash, 2000, 1000);
		time += 2000 + 0 + 1000*3;
		/*t2.schedule(sweepGround, (time+500));
		time += 500 + 500 + 0;
		t3.schedule(goCenter, (time+2000));
		time += 2000 + 0 + 0;*/
		
	}//attackSequence
	
	
	
	
	private void dash(double spdx, double spdy) {
		deg = 0;
		xspeed = spdx;
		yspeed = spdy;
	}//dash()
	
	private void dashTowards (int x, int y, double spd) {
		deg = 0;
		double h = Math.atan2(y, x);
		xspeed = spd*Math.cos(h)*Math.signum(x-(this.x+CENTER_X));
		yspeed = spd*Math.sin(h)*Math.signum(y-(this.y+CENTER_Y));
		
		
		if (xspeed < 0 && yspeed < 0) deg = h*100-45; //top left
		if (xspeed > 0 && yspeed < 0) deg = h*100-90; //top right
		if (xspeed < 0 && yspeed > 0) deg = 90+h*100+180; //bottom left
		//if (xspeed > 0 && yspeed > 0) deg = -h*100-90; //bottom right
		
		
	}//dashTowards
	
	
	//TODO dash to a specific point. use to replace tp
	private void dashTo (int x, int y, double spd) {
		
	}
	
	
	public void draw (Graphics2D gtd) {
		sprite.draw(gtd, x, y);
	}
	
	void set(int cameraX) {
		if (gravEnabled) yspeed += GRAVITY;
		
		if (xspeed > 0 && xspeed < 0.75 || xspeed < 0 && xspeed > -0.75) {
			xspeed = 0;
		}
		if (xspeed > xMaxSpeed) {
			xspeed = xMaxSpeed;
		}
		if (xspeed < xMaxSpeed*-1) {
			xspeed = xMaxSpeed*-1;
		}
		
		if (collision) {
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
				}//if
			}//for
			
		}//if collision
		
		//update movement
		x = startX + cameraX;
		startX += xspeed;
		y += yspeed;
		hitBox.x = x;
		hitBox.y = y;
	}//set

}
