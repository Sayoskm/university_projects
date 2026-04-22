package Music_1;

public class Beat {
    private int time;
    private String nodeName;
    public int getTime() {
        return time;
    }
    public void setTime(int time) {
        this.time = time;
    }
    public String getNodeName() {
        return nodeName;
    }
    public void setNodeName(String nodeName) {
        this.nodeName = nodeName;
    }
    public Beat(int time, String nodeName) {
        this.time = time;
        this.nodeName = nodeName;
    }
    
}
