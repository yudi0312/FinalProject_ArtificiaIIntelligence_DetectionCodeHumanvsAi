public class QueueUsingArray {
    private int[] data;
    private int front=0,rear=-1,size=0;

    public QueueUsingArray(int capacity){ data=new int[capacity]; }
    public void enqueue(int value){ data[++rear]=value; size++; }
    public int dequeue(){ size--; return data[front++]; }

    public static void main(String[] args){
        QueueUsingArray q=new QueueUsingArray(10);
        q.enqueue(5); q.enqueue(6);
        System.out.println(q.dequeue());
    }
}