package Music_1;
import javax.swing.*;
import java.awt.*;

public class DrawImagePanel extends JPanel {

    public static Game game;

    public DrawImagePanel(String difficulty) {
        setOpaque(false);  // 設置面板為透明
        game = new Game(difficulty);
        game.start();
        setFocusable(true);
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g); 
        
        Graphics2D g2d = (Graphics2D) g;
        g2d.setComposite(AlphaComposite.getInstance(AlphaComposite.SRC_OVER, 0.7f));
        game.screenDraw(g2d);  
        
        g2d.setComposite(AlphaComposite.getInstance(AlphaComposite.SRC_OVER, 0.9f));
        game.playingDraw(g2d); 
    } 
}
