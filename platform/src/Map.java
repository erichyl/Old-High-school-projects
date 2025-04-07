import java.awt.Color;
import java.awt.Graphics2D;
import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;


public class Map {

	private int width;
	private int height;
	private ArrayList<Wall> tiles;
	
	public Map () {
		tiles = new ArrayList<>();
		this.loadTileMap();
	}
	
	public ArrayList<Wall> getTiles() {
		return tiles;
	}
	
	void loadTileMap() {
		//Getting file input
		try {
			File messageFile = new File("bin/tilemap.txt");
			Scanner read = new Scanner(messageFile);
			width = Integer.parseInt(read.nextLine());
			height = Integer.parseInt(read.nextLine());
            for (int y = 0; y < height; y++) {
            	String[] array = read.nextLine().split(" ");
            	for (int x = 0; x < width; x++) {
            		if (!array[x].equals("00")) {
            			tiles.add(new Wall(x*32-400, y*32-16, "sprites/tile" + array[x] + ".png"));
            		}
            	}

            }  
		    
		} catch (Exception e) {
			System.out.println("Failed to load message.txt: " + e);
	
		}//try catch

			
	}//loadMessage
	
}//map