import java.util.*;
public class Main
{
     public static int n;
    Node tail=null;
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
        Node newnode=new Node(data);
        if(tail==null)
        {
            tail=newnode;
            tail.next=newnode;
        }
        else
        {
            newnode.next=tail.next;
            tail.next=newnode;
            tail=newnode;
        }
    }
    public void deletefrombeginning(){
        if(tail==null)
        {
            return;
        }
        else
        {
            tail.next=tail.next.next;
        }
    }
    public void deletefromPosition(int pos){
        Node current=tail.next;
        int i=1;
      
        if(pos>n||pos<=0){
            System.out.println("Invalid Position.");
            
        }
        else{
        if(tail==null)
        {
            return;
        }
        else if(current.next==current){
            tail=null;
        }
        else if(pos==1)
        {
            deletefrombeginning();
        }
        else
        {
            while(i<pos-1){
                current=current.next;
                i++;
            }
            Node nextNode=current.next;
            current.next=nextNode.next;
        }
        }
    }
    public void display(){
        if(tail==null)
        {
            return ;
        }
        else{
            Node current=tail.next;
            do{
                System.out.print(current.data+ " ");
                current=current.next;
        }while(current!=tail.next);
        }
    }

	public static void main(String[] args) {
	
		Main ob=new Main();
      Scanner s=new Scanner(System.in);
      
      System.out.println("Enter No of elements to insert in circular linked list.");
	    n=s.nextInt();
	    System.out.println("Enter list elements.");
	    for(int i=0;i<n;i++){
	        ob.insert(s.nextInt());
	    }
	    System.out.println("Circular Linked list : ");
	  ob.display();
	  System.out.println("\nEnter the position of node which you want to delete.");
	  ob.deletefromPosition(s.nextInt());    // Delete node from given Position.
	  System.out.println("\nCircular Linked List after deleting node from given Position: ");
	  ob.display();
	    
	}
}
