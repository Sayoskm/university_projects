package Music_1;

import javax.swing.*;
import javax.swing.border.LineBorder;

import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

public class frame extends JFrame{

    private Image wallpaper, songpage;
    private JPanel mainpage, song, level;

    private JButton easyButton;
    private music selectedMusic;
    private int nowSelected = 0;

    private boolean isSelect = false;
    private boolean isGame = false;

    private Timer repaintTimer;
    private DrawImagePanel panel;

    public frame() {
        setTitle("Last Summer");
        setSize(main.scn_width, main.scn_height);
        setLocationRelativeTo(null);
        setResizable(false);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        //載入一張圖片並將其轉換為 Image 物件，設定視窗背景
        wallpaper = new ImageIcon(main.class.getResource("/resource/MainWallpaper.jpg")).getImage();

        selectedMusic = new music("LastSummer.mp3", true);
        selectedMusic.start();

        //鍵盤監聽
        KeyListener keyListener = new KeyListener();
        this.addKeyListener(keyListener);
        this.setFocusable(true);  // 確保可以監聽事件
        this.requestFocusInWindow();  // 確保獲得焦點

         // 設定背景圖片繪製
        mainpage = new JPanel() {
            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g); // 確保 JPanel 的繪製邏輯被呼叫
                Graphics2D g2d = (Graphics2D) g;
                // Set the transparency level (alpha value between 0.0 and 1.0)
                float alpha = 0.5f; // 50% opacity
                AlphaComposite alphaComposite = AlphaComposite.getInstance(AlphaComposite.SRC_OVER, alpha);
                g2d.setComposite(alphaComposite);
                g2d.drawImage(wallpaper, 0, 0, getWidth(), getHeight(), this); // 繪製背景圖片
            }
        };

        // 設定選取介面繪製
        songpage = new ImageIcon(main.class.getResource("/resource/lastSummerSong.jpg")).getImage();
        song = new JPanel() {
            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g); // 確保 JPanel 的繪製邏輯被呼叫
                g.drawImage(songpage, 0, 0, getWidth(), getHeight(), this); // 繪製背景圖片
            }
        };
        song.setPreferredSize(new Dimension(523, 415));
        song.setBorder(new LineBorder(Color.BLACK, 5));

        level = new JPanel();
        level.setOpaque(false);
        easyButton = new JButton("PLAY GAME!");
        level.add(easyButton);
        level.setLayout(new FlowLayout());  // 設定 FlowLayout 使按鈕按順序排列
        //控制按鍵
        easyButton.addMouseListener(new  MouseAdapter() {
            @Override
            public void mousePressed(MouseEvent e){
                isSelect = false;
                isGame = true;
                gameStart(nowSelected, "EASY");
            }
        });

        song.setBounds((main.scn_width - 523) / 2, 50, 523, 415);
        level.setBounds((main.scn_width - 300) / 2, 500, 300, 50);
        getContentPane().add(song);
        getContentPane().add(level);
        getContentPane().add(mainpage, BorderLayout.CENTER);

        setVisible(true);
    }

    public void gameStart(int nowSelected, String difficulty){//進入遊戲的頁面轉換
        if (selectedMusic != null) selectedMusic.close();
        level.setVisible(false);
        song.setVisible(false);
        getContentPane().remove(mainpage);
        wallpaper = new ImageIcon(main.class.getResource("/resource/LastSummerWallpaper.jpg")).getImage();
        mainpage = new JPanel() {
            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g); // 確保 JPanel 的繪製邏輯被呼叫
                Graphics2D g2d = (Graphics2D) g;
                // Set the transparency level (alpha value between 0.0 and 1.0)
                float alpha = 0.5f; // 50% opacity
                AlphaComposite alphaComposite = AlphaComposite.getInstance(AlphaComposite.SRC_OVER, alpha);
                g2d.setComposite(alphaComposite);
                g2d.drawImage(wallpaper, 0, 0, getWidth(), getHeight(), this); // 繪製背景圖片
                g2d.setFont(new Font("Arial", Font.BOLD, 30));
                g2d.drawString(difficulty, 100, 100);
            }
        };
        mainpage.setPreferredSize(new Dimension(800, 700));
        mainpage.setLayout(null);
        mainpage.setOpaque(false);
        //繪製node的出現路徑&node
        panel = new DrawImagePanel(difficulty);
        panel.setBounds(340, 0, 600, 800);

        // Create and start a Timer to call repaint every 30ms
        repaintTimer = new Timer(30, e -> panel.repaint());
        repaintTimer.start();

        mainpage.add(panel);

        getContentPane().add(mainpage);
    }
}
