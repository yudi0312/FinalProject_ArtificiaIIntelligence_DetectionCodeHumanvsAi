public class CircularQueue {
    private int[] data;
    private int front=0,rear=0,size=0;

    public CircularQueue(int capacity){ data=new int[capacity]; }
    public void enqueue(int value){ data[rear]=value; rear=(rear+1)%data.length; size++; }
    public int dequeue(){ int v=data[front]; front=(front+1)%data.length; size--; return v; }

    public static void main(String[] args){
        CircularQueue q=new CircularQueue(5);
        q.enqueue(1); q.enqueue(2);
        System.out.println(q.dequeue());
    }
}