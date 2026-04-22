package Music_1;

import java.awt.*;
import javax.swing.*;
import java.util.ArrayList;

public class Game extends Thread{

    private Image nodeRouteCImage = new ImageIcon(getClass().getResource("/resource/nodeRoute.png")).getImage();
    private Image nodeRouteVImage = new ImageIcon(getClass().getResource("/resource/nodeRoute.png")).getImage();
    private Image nodeRouteBImage = new ImageIcon(getClass().getResource("/resource/nodeRoute.png")).getImage();
    private Image nodeRouteNImage = new ImageIcon(getClass().getResource("/resource/nodeRoute.png")).getImage();
    private Image nodeRouteMImage = new ImageIcon(getClass().getResource("/resource/nodeRoute.png")).getImage();
    private Image judgeZone = new ImageIcon(getClass().getResource("/resource/judgeZone.png")).getImage();
    private String ranking = "",result = "";

    ArrayList<Node> nodeList = new ArrayList<Node>();

    private String titleName ,difficulty;
    private Font font = new Font("Arial", Font.BOLD, 40);

    private music buttonEnteredMusic;

    public Game(String difficulty) {
        this.titleName = "Last Summer";
        this.difficulty = difficulty;
        //播放關卡音樂
        buttonEnteredMusic = new music("LastSummer.mp3",false);
    }
    

    public void screenDraw (Graphics2D g){
        g.drawImage(nodeRouteCImage, 2, 0, null);
        g.drawImage(nodeRouteVImage, 122, 0, null);
        g.drawImage(nodeRouteBImage, 242, 0, null);
        g.drawImage(nodeRouteNImage, 362, 0, null);
        g.drawImage(nodeRouteMImage, 482, 0, null);
        
        //放上判定區域
        g.drawImage(judgeZone, 0, 600, null);

        g.setFont(new Font("Arial", Font.BOLD, 60));
        g.drawString(result, 100, 200);
    }
    public void playingDraw(Graphics2D g2d){
        //出現判定結果
        g2d.setFont(font);
        FontMetrics metrics = g2d.getFontMetrics(font);
        int textWidth = metrics.stringWidth(ranking);
        int x = (600 - textWidth) / 2;
        g2d.drawString(ranking, x, 200);

        for(int i=0;i<nodeList.size();i++){
            Node node = nodeList.get(i);
            if (node.getY() >630){
                ranking = "MISS";
            }
            if (!node.isProceed()){
                nodeList.remove(i);
                i--;
            }
            else{
                node.screenDraw(g2d);
            }
        }
    }
    public void pressC(){
        judge("C");
        nodeRouteCImage = new ImageIcon(getClass().getResource("/resource/nodeRoute1.png")).getImage();
        //new music ("",false).start(); 打擊音
    }
    public void releaseC(){
        nodeRouteCImage = new ImageIcon(getClass().getResource("/resource/nodeRoute.png")).getImage();

    }
    public void pressV(){
        judge("V");
        nodeRouteVImage = new ImageIcon(getClass().getResource("/resource/nodeRoute1.png")).getImage();
        //new music ("",false).start(); 打擊音
    }
    public void releaseV(){
        nodeRouteVImage = new ImageIcon(getClass().getResource("/resource/nodeRoute.png")).getImage();

    }
    public void pressB(){
        judge("B");
        nodeRouteBImage = new ImageIcon(getClass().getResource("/resource/nodeRoute1.png")).getImage();
        //new music ("",false).start(); 打擊音
    }
    public void releaseB(){
        nodeRouteBImage = new ImageIcon(getClass().getResource("/resource/nodeRoute.png")).getImage();

    }
    public void pressN(){
        judge("N");
        nodeRouteNImage = new ImageIcon(getClass().getResource("/resource/nodeRoute1.png")).getImage();
        //new music ("",false).start(); 打擊音
    }
    public void releaseN(){
        nodeRouteNImage = new ImageIcon(getClass().getResource("/resource/nodeRoute.png")).getImage();

    }
    public void pressM(){
        judge("M");
        nodeRouteMImage = new ImageIcon(getClass().getResource("/resource/nodeRoute1.png")).getImage();
        //new music ("",false).start(); 打擊音
    }
    public void releaseM(){
        nodeRouteMImage = new ImageIcon(getClass().getResource("/resource/nodeRoute.png")).getImage();

    }
    public void close(){
        buttonEnteredMusic.close();
        this.interrupt();
    }
    @Override
    public void run(){
        dropNotes();
    }
    public void dropNotes(){
        Beat[] beats= null;
        if (titleName.equals("Last Summer")&&difficulty.equals("EASY")){
            int startTime = 2220 - main.reach_time*1000;
            int gap = 100;
            beats = new Beat[]{
                new Beat(startTime, "B"),
                new Beat(startTime+gap*11, "C"),
                new Beat(startTime+gap*18, "V"),
                new Beat(startTime+gap*25, "B"),
                new Beat(startTime+gap*36, "M"),
                new Beat(startTime+gap*45, "N"),
                new Beat(startTime+gap*52, "B"),
                new Beat(startTime+gap*63, "V"),
                new Beat(startTime+gap*72, "N"),
                new Beat(startTime+gap*79, "B"),
                new Beat(startTime+gap*80, "C"),
                new Beat(startTime+gap*89, "M"),
                new Beat(startTime+gap*98, "V"),           
                new Beat(startTime+gap*102, "C"),
                new Beat(startTime+gap*105, "B"),
                new Beat(startTime+gap*113, "N"),
                new Beat(startTime+gap*113, "C"),
                new Beat(startTime+gap*127, "B"),
                new Beat(startTime+gap*138, "M"),
                new Beat(startTime+gap*142, "N"),
                new Beat(startTime+gap*142, "C"),
                new Beat(startTime+gap*149, "M"),
                new Beat(startTime+gap*153, "V"),
                new Beat(startTime+gap*166, "B"),
                new Beat(startTime+gap*170, "N"),
                new Beat(startTime+gap*174, "C"),
                new Beat(startTime+gap*176, "B"),
                new Beat(startTime+gap*179, "M"),
                new Beat(startTime+gap*185, "N"),
                new Beat(startTime+gap*200, "N"),
                new Beat(startTime+gap*208, "N"),
                new Beat(startTime+gap*220, "B"),
                new Beat(startTime+gap*227, "C"),
                new Beat(startTime+gap*234, "M"),
                new Beat(startTime+gap*246, "B"),
                new Beat(startTime+gap*253, "N"),
                new Beat(startTime+gap*260, "C"),
                new Beat(startTime+gap*272, "B"),
                new Beat(startTime+gap*279, "M"),
                new Beat(startTime+gap*286, "M"),
                new Beat(startTime+gap*298, "B"),
                new Beat(startTime+gap*305, "C"),
                new Beat(startTime+gap*312, "V"),
                new Beat(startTime+gap*326, "N"),
                new Beat(startTime+gap*333, "M"),
                new Beat(startTime+gap*340, "N"),
                new Beat(startTime+gap*353, "V"),
                new Beat(startTime+gap*360, "C"),
                new Beat(startTime+gap*367, "B"),
                new Beat(startTime+gap*373, "B"),
                new Beat(startTime+gap*380, "V"),
                new Beat(startTime+gap*387, "V"),
                new Beat(startTime+gap*393, "N"),
                new Beat(startTime+gap*400, "M"),
                new Beat(startTime+gap*406, "C"),
                new Beat(startTime+gap*412, "B"),
                new Beat(startTime+gap*428, "N"),
                new Beat(startTime+gap*437, "M"),
                new Beat(startTime+gap*444, "N"),
                new Beat(startTime+gap*453, "V"),
                new Beat(startTime+gap*462, "B"),
                new Beat(startTime+gap*469, "V"),
                new Beat(startTime+gap*478, "B"),
                new Beat(startTime+gap*489, "C"),
                new Beat(startTime+gap*496, "V"),
                new Beat(startTime+gap*505, "C"),
                new Beat(startTime+gap*508, "N"),
                new Beat(startTime+gap*516, "M"),
                new Beat(startTime+gap*516, "C"),
                new Beat(startTime+gap*520, "V"),
                new Beat(startTime+gap*520, "N"),
                new Beat(startTime+gap*523, "B"),

                new Beat(startTime+gap*532, "B"),
                new Beat(startTime+gap*543, "C"),
                new Beat(startTime+gap*550, "V"),

                new Beat(startTime+gap*559, "C"),
                new Beat(startTime+gap*570, "N"),
                new Beat(startTime+gap*577, "B"),
                new Beat(startTime+gap*577, "M"),

                new Beat(startTime+gap*586, "B"),
                new Beat(startTime+gap*597, "N"),
                new Beat(startTime+gap*604, "C"),
                new Beat(startTime+gap*604, "B"),

                new Beat(startTime+gap*613, "V"),
                new Beat(startTime+gap*616, "N"),
                new Beat(startTime+gap*624, "B"),
                new Beat(startTime+gap*628, "V"),
                new Beat(startTime+gap*628, "N"),
                new Beat(startTime+gap*631, "C"),
                new Beat(startTime+gap*631, "M"),
            };
        }
        int i=0;
        buttonEnteredMusic.start();
        while(i<beats.length){
            boolean dropped = false;
            if (beats[i].getTime()<=buttonEnteredMusic.getTime()){
                Node node = new Node(beats[i].getNodeName());
                node.start();
                nodeList.add(node);
                i++;
                dropped =true;
            }
            if(! dropped){
                try{
                    Thread.sleep(5);
                } catch (Exception e){
                    e.printStackTrace();
                }
            }
        }
    }
    public void judge(String input){
        for(int i=0;i<nodeList.size();i++){
            Node node = nodeList.get(i);
            if (input.equals(node.getNodeType())){
                ranking = node.judge();
                break;
            }
        }
    }
}