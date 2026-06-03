public class DequeImplementation {
    private int[] data=new int[20];
    private int front=10,rear=10;

    public void addFront(int v){ data[--front]=v; }
    public void addRear(int v){ data[rear++]=v; }
    public int removeFront(){ return data[front++]; }
    public int removeRear(){ return data[--rear]; }

    public static void main(String[] args){
        DequeImplementation d=new DequeImplementation();
        d.addFront(1); d.addRear(2);
        System.out.println(d.removeFront());
    }
}