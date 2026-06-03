public class QueueUsingLinkedList {
    static class Node{ int data; Node next; Node(int d){data=d;} }
    private Node front,rear;

    public void enqueue(int value){
        Node n=new Node(value);
        if(rear==null){front=rear=n; return;}
        rear.next=n; rear=n;
    }
    public int dequeue(){
        int v=front.data; front=front.next;
        if(front==null) rear=null;
        return v;
    }

    public static void main(String[] args){
        QueueUsingLinkedList q=new QueueUsingLinkedList();
        q.enqueue(10); q.enqueue(20);
        System.out.println(q.dequeue());
    }
}