package Music_1;

import java.awt.*;
import javax.swing.*;

public class Node extends Thread{
    private Image playingNode = new ImageIcon(main.class.getResource("/resource/playingNode.png")).getImage();
    private int x, y=600-(1000/main.sleep_time*main.node_speed)*main.reach_time;
    private String nodeType;
    private boolean proceeded = true;

    public String getNodeType(){
        return nodeType;
    }

    public boolean isProceed(){
        return proceeded;
    }
    public void close(){
        proceeded = false;
    }

    public Node(String nodeType){
        if (nodeType.equals("C")){
            x=2;
        }
        else if (nodeType.equals("V")){
            x=122;
        }
        else if (nodeType.equals("B")){
            x=242;
        }
        else if (nodeType.equals("N")){
            x=362;
        }
        else if (nodeType.equals("M")){
            x=482;
        }
        this.nodeType = nodeType;
    }

    public void screenDraw(Graphics2D g){
        g.drawImage(playingNode, x, y,null);
    }
    public void drop(){
        y+=main.node_speed;
        if (y>630){
            System.out.println("miss");
            close();
        }

    }
    @Override
    public void run(){
        try{
            while (true){
                drop();
                if (proceeded){
                    Thread.sleep(main.sleep_time);
                }
                else{
                    break;
                }
            }
        }catch(Exception e){
            System.err.println(e.getMessage());
        }
    }

    public String judge(){
        String rank = "";
        if(y>=620){
            System.out.println("bad");
            close();
            rank = "BAD";
        }
        else if(y>=610){
            System.out.println("good");
            close();
            rank = "GOOD";
        }
        else if(y>=590){
            System.out.println("great");
            close();
            rank = "GREAT";
        }
        else if(y>=580){
            System.out.println("perfect");
            close();
            rank = "PERFECT";
        }
        else if(y>=565){
            System.out.println("great");
            close();
            rank = "GREAT";
        }
        else if(y>=550){
            System.out.println("good");
            close();
            rank = "GOOD";
        }
        else if(y>=535){
            System.out.println("bad");
            close();
            rank = "BAD";
        }
        return rank;
    }
    public int getY(){
        return y;
    }
}
