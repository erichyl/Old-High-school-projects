import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.util.ArrayList;
import java.util.Timer;
import java.util.TimerTask;

public class GamePanel extends javax.swing.JPanel implements ActionListener{
	
	Player player;
	Boss boss;
	ArrayList<Wall> walls = new ArrayList<Wall>();
	Timer gameTimer;
	Sprite background;
	int cameraX = 150;
	
	public GamePanel () {
		player = new Player(600, 300, this);
		boss = new Boss(500, 80, "sprites/betteralien.png", this);
		//makeWalls();
		Map map = new Map();
        walls = map.getTiles();
        background = (SpriteStore.get()).getSprite("sprites/Background1.png");
        
		gameTimer = new Timer();
		gameTimer.schedule(new TimerTask() {
			@Override
			public void run() {
				
				player.set();
				boss.set(cameraX);
				for (Wall w : walls) {
					w.set(cameraX);
				}
				repaint();
			}
		}, 0, 17);
	} 
	
	public void makeWalls (){
		for (int i = 48; i < 624; i += 48) {
			walls.add(new Wall(i, 576, "sprites/tile.png"));
		}
		walls.add(new Wall(48, 528, "sprites/tile.png"));
		walls.add(new Wall(48, 480, "sprites/tile.png"));
		walls.add(new Wall(48, 432, "sprites/tile.png"));
		walls.add(new Wall(432, 528, "sprites/tile.png"));
		walls.add(new Wall(480, 528, "sprites/tile.png"));
		walls.add(new Wall(480, 480, "sprites/tile.png"));
		walls.add(new Wall(144, 288, "sprites/tile.png"));
		walls.add(new Wall(288, 384, "sprites/tile.png"));
	}
	
	public void paint (Graphics g) {
		super.paint(g);
		
		Graphics2D gtd = (Graphics2D) g;
		
		background.draw(gtd, 0, 0);
		
		player.draw(gtd);
		boss.draw(gtd);
		for (Wall w: walls) {
			w.draw(gtd);
		}
	}
	public void keyPressed(KeyEvent e) {
			if (e.getKeyChar() == 'a') {
				player.leftPressed = true;
			}
			if (e.getKeyChar() == 'd') {
				player.rightPressed = true;
			}
			if (e.getKeyChar() == 'w') {
				player.upPressed = true;
			}
			if (e.getKeyChar() == 's') {
				player.downPressed = true;
			}
		}
	public void keyReleased(KeyEvent e) {
		if (e.getKeyChar() == 'a') {
				player.leftPressed = false;
			}
			if (e.getKeyChar() == 'd') {
				player.rightPressed = false;
			}
			if (e.getKeyChar() == 'w') {
				player.upPressed = false;
			}
			if (e.getKeyChar() == 's') {
				player.downPressed = false;
			}
	}
	@Override
	public void actionPerformed(ActionEvent ae) {
		
	}
	
}
