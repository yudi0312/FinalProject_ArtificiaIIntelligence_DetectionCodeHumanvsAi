import java.util.*;
public class Main
{
    Node head=null;
    static class Node{
        int data;
        Node next;
    
    Node(int item){
        data=item;
        next=null;
    }
    }
    public void insert(int data)
    {
        Node node=new Node(data);
        if(head==null)
        {
            head=node;
        }
        else
        {
            Node n=head;
            while(n.next!=null)
            {
                n=n.next;
            }
            n.next=node;
        }
    }
   
    public void reverse()
    {
       Node currentnode=head;
       Node prevnode=null;
       Node nextnode=head;
       while(nextnode!=null){
           nextnode=nextnode.next;
           currentnode.next=prevnode;
           prevnode=currentnode;
           currentnode=nextnode;
       }
       head=prevnode;
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
      
      System.out.println("Enter No of elements to insert in linked list.");
	    int n=s.nextInt();
	    System.out.println("Enter list elements.");
	    for(int i=0;i<n;i++){
	        ob.insert(s.nextInt());
	    }
	    System.out.println("Linked list : ");
	    ob.display();
	    
	    ob.reverse();
	    
	    System.out.println("\nReverse Linked list : ");
	    ob.display();
	   
	}
}



