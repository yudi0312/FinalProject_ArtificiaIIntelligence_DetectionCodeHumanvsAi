public class StackUsingLinkedList {
    static class Node { int data; Node next; Node(int d){data=d;} }
    private Node top;

    public void push(int value){ Node n=new Node(value); n.next=top; top=n; }
    public int pop(){ int v=top.data; top=top.next; return v; }

    public static void main(String[] args){
        StackUsingLinkedList s=new StackUsingLinkedList();
        s.push(1); s.push(2);
        System.out.println(s.pop());
    }
}