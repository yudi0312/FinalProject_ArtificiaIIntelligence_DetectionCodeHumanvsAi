import java.util.*;
public class Main
{
    Node head,tail=null;
    static class Node{
        int data;
        Node next;
        Node prev;
    
    Node(int item){
        data=item;
        next=null;
        prev=null;
    }
    }
    public void insert(int data)
    {
        Node newnode=new Node(data);
        if(head==null)
        {
            head=newnode;
            tail=newnode;
            head.next=head;
            head.prev=head;
        }
        else
        {
            tail.next=newnode;
            newnode.prev=tail;
            newnode.next=head;
            head.prev=newnode;
            tail=newnode;
        }
    }
    public void display(){
        if(head==null)
        {
            return ;
        }
        Node temp=head;
        do{
            System.out.print(temp.data+ " ");
            temp=temp.next;
        }while(temp!=tail.next);
    }

	public static void main(String[] args) {
	
		Main ob=new Main();
      Scanner s=new Scanner(System.in);
      
      System.out.println("Enter No of elements to insert in doubly Circular linked list.");
	    int n=s.nextInt();
	    System.out.println("Enter list elements.");
	    for(int i=0;i<n;i++){
	        ob.insert(s.nextInt());
	    }
	    System.out.println("Doubly Circular Linked list : ");
	  ob.display();
	    
	}
}


