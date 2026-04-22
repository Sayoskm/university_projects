package Music_1;

import java.io.BufferedInputStream;
import java.io.InputStream;
import javazoom.jl.player.Player;

public class music extends Thread {

    private Player player;
    private boolean isLoop;
    private BufferedInputStream bis;

    public music(String name, boolean isLoop) {
        try {
            this.isLoop = isLoop;
            // 使用 getResourceAsStream 來讀取 JAR 包中的音樂檔案
            InputStream inputStream = getClass().getResourceAsStream("/Music_1/" + name);
            if (inputStream == null) {
                throw new Exception("Audio file not found: " + name);
            }
            bis = new BufferedInputStream(inputStream);
            player = new Player(bis); // 初始化播放器
        } catch (Exception e) {
            System.out.println("Error initializing music player: " + e.getMessage());
        }
    }

    public int getTime() {
        if (player == null) return 0;
        return player.getPosition();
    }

    public void close() {
        isLoop = false;
        if (player != null) {
            player.close();
        }
        this.interrupt();
    }

    @Override
    public void run() {
        try {
            if (player != null) {
                do {
                    player.play();
                } while (isLoop); // 如果需要循環播放，則繼續播放
            } else {
                System.out.println("Player is not initialized.");
            }
        } catch (Exception e) {
            System.out.println("Error playing music: " + e.getMessage());
        }
    }
}
