import java.util.*;
public class Main
{   static Scanner s=new Scanner(System.in);
    static int n=5; //assuming queue size is 5.
    static int front=-1;
    static int rear=-1;
    static int queue[]=new int[n];
    
    static void enqueue(){
        System.out.println("Enter data");
        int data=s.nextInt();
        if((rear+1)%n==front){
            System.out.println("queue is full");
        }
        else if(front==-1&&rear==-1){
            front=rear=0;
            queue[rear]=data;
        }
        else{
            rear=(rear+1)%n;
            queue[rear]=data;
        }
    }
    
    static void dequeue(){
        int item;
        if(front==-1&&rear==-1)
        {
            System.out.println("Queue Empty");
        }
        else if(front==rear)
        {
            System.out.println("Dequeued element is "+queue[front]+"\nQueue is now Empty");
            front=rear=-1;
        }
        else{
            item=queue[front];
            front=(front+1)%n;
            System.out.println("Dequeued element is "+item);
        }
        
    }
    static void peek()
    {
        if(front==-1&&rear==-1)
        {
            System.out.println("Queue Empty");
        }
        else
        {
            System.out.println("Top most element is "+queue[front]);
        }
    }
    static void display(){
       int i=front;
        if(front==-1&&rear==-1){
            System.out.println("Queue Empty");
        }
        else{
        System.out.println("Queue elements are : ");
       while(i!=rear)
        {
            System.out.print(queue[i]+" ");
            i=(i+1)%n;
        }
        System.out.print(queue[rear]+"\n");
        }
    }
	public static void main(String[] args) {
	    System.out.println("*****Circular Queue Implementation Using Array*****");
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
