import java.awt.Color;

public class MainFrame extends javax.swing.JFrame {
	public MainFrame () {
		GamePanel panel = new GamePanel();
		panel.setLocation(0, 0);
		panel.setSize(this.getSize());
		panel.setBackground(Color.GRAY);
		panel.setVisible(true);
		this.add(panel);
		
		addKeyListener(new KeyChecker(panel));
	}
	
}
