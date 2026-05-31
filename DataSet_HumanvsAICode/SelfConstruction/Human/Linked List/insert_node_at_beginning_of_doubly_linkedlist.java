import java.util.*;
public class Main
{
    Node head=null;
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
        Node temp=head;
        if(head==null)
        {
            head=temp=newnode;
        }
        else
        {
            while(temp.next!=null)
            {
                temp=temp.next;
            }
            temp.next=newnode;
            newnode.prev=temp;
            temp=newnode;
        }
    }
    public void insertAtBeginning(int item){
        Node newnode=new Node(item);
        head.prev=newnode;
        newnode.next=head;
        newnode.prev=null;
        head=newnode;
        
    }
    public void display(){
        if(head==null)
        {
            return ;
        }
        Node current=head;
        while(current!=null){
            System.out.print(current.data+ " ");
            current=current.next;
        }
    }

	public static void main(String[] args) {
	
		Main ob=new Main();
      Scanner s=new Scanner(System.in);
      
      System.out.println("Enter No of elements to insert in Doubly linked list.");
	    int n=s.nextInt();
	    System.out.println("Enter list elements.");
	    for(int i=0;i<n;i++){
	        ob.insert(s.nextInt());
	    }
	    System.out.println("Doubly Linked list : ");
	    ob.display();
	    
	    System.out.println("\nEnter element to insert at beginning of Doubly Linked list");
	    ob.insertAtBeginning(s.nextInt());
	    
	      System.out.println("Doubly Linked list after inserting element at Beginning : ");
	    ob.display();
	    
	    
	}
}
