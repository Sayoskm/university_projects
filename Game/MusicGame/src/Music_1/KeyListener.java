package Music_1;

import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.*;

public class KeyListener extends KeyAdapter{
    @Override
    public void keyPressed(KeyEvent e) {
        if (DrawImagePanel.game == null){
            return;
        }
        if (e.getKeyCode() == KeyEvent.VK_C){
            DrawImagePanel.game.pressC();
        }
        else if (e.getKeyCode() == KeyEvent.VK_V){
            DrawImagePanel.game.pressV();
        }
        else if (e.getKeyCode() == KeyEvent.VK_B){
            DrawImagePanel.game.pressB();
        }
        else if (e.getKeyCode() == KeyEvent.VK_N){
            DrawImagePanel.game.pressN();
        }
        else if (e.getKeyCode() == KeyEvent.VK_M){
            DrawImagePanel.game.pressM();
        }
    }
    @Override
    public void keyReleased(KeyEvent e){
        if (DrawImagePanel.game == null){
            return;
        }
        if (e.getKeyCode() == KeyEvent.VK_C){
            DrawImagePanel.game.releaseC();
        }
        else if (e.getKeyCode() == KeyEvent.VK_V){
            DrawImagePanel.game.releaseV();
        }
        else if (e.getKeyCode() == KeyEvent.VK_B){
            DrawImagePanel.game.releaseB();
        }
        else if (e.getKeyCode() == KeyEvent.VK_N){
            DrawImagePanel.game.releaseN();
        }
        else if (e.getKeyCode() == KeyEvent.VK_M){
            DrawImagePanel.game.releaseM();
        }
    }
}
