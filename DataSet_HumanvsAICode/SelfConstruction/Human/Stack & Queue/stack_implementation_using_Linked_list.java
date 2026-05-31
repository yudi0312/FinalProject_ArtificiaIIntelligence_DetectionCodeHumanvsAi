import java.util.*;
public class Main
{   static Scanner s=new Scanner(System.in);
    
     static Node top=null;
    static class Node{
        int data;
        Node next;
        
    
    Node(int item){
        data=item;
        next=null;
    }
    }
    static void push(){
        System.out.println("Enter data");
        int x=s.nextInt();
        Node newnode=new Node(x);
        newnode.next=top;
        top=newnode;
    }
    static void pop(){
       Node temp=top;
       if(top==null)
       {
            System.out.println("list empty!");
       }
       else
       {
           System.out.println("Popped element is "+temp.data);
           top=top.next;
           
       }
        
    }
    static void peek()
    {
       if(top==null)
       {
            System.out.println("list empty!");
       }
       else{
           System.out.println("Top element of list is " +top.data);
       }
    }
    static void display(){
        Node temp=top;
        if(top==null)
        {
            System.out.println("list empty!");
        }
        else
        {
            System.out.println("Stack elements are : ");
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
	         System.out.println("Enter 1 for push operation\nEnter 2 for pop operation\nEnter 3 for peek operation(i.e to see top most element)\nEnter 4 to display stack");
	    int choice=s.nextInt();
	    switch(choice){
	        case 1:
	            push();
	            break;
	        case 2:
	            pop();
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
