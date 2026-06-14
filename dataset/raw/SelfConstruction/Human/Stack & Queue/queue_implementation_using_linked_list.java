import java.util.*;
public class Main
{   static Scanner s=new Scanner(System.in);
    static  Node front=null;
     static   Node rear=null;
     static Node top=null;
    static class Node{
        int data;
        Node next;
       
        
    
    Node(int item){
        data=item;
        next=null;
    }
    }
    static void enqueue(){
        System.out.println("Enter data");
        int x=s.nextInt();
        Node newnode=new Node(x);
        newnode.next=null;
        if(front==null&&rear==null)
        {
            front=rear=newnode;
        }
        else
        {
            rear.next=newnode;
            rear=newnode;
        }
        
    }
    static void dequeue(){
       Node temp=front;
       if(front==null&&rear==null)
       {
            System.out.println("list empty!");
       }
       else
       {
           System.out.println("Popped element is "+temp.data);
           front=front.next;
           
       }
        
    }
    static void peek()
    {
       if(front==null&&rear==null)
       {
            System.out.println("list empty!");
       }
       else{
           System.out.println("Top element of list is " +front.data);
       }
    }
    static void display(){
        Node temp=front;
        if(front==null&&rear==null)
        {
            System.out.println("list empty!");
        }
        else
        {
            System.out.println("Queue elements are : ");
            while(temp!=null)
            {
                System.out.print(temp.data+" ");
                temp=temp.next;
            }
            System.out.print("\n");
            
        }
    }
	public static void main(String[] args) {
	   
	    char c;
	    do{
	         System.out.println("Enter 1 for enqueue operation\nEnter 2 for dequeue operation\nEnter 3 for peek operation(i.e to see top most element)\nEnter 4 to display queue");
	    int choice=s.nextInt();
	    switch(choice){
	        case 1:
	           enqueue();
	            break;
	        case 2:
	            dequeue();
	            break;
	        case 3:
	            peek();
	            break;
	        case 4:
	            display();
	            break;
	      
	    }
	    System.out.println("press y to continue and n to exit");
	     c = s.next().charAt(0); 
	    }while(c!='n');
	    
	    
	}
}
