import java.util.*;
public class Main
{   static Scanner s=new Scanner(System.in);
    static int n=5; //assuming stack size is 5.
    static int top=-1;
    static int stack[]=new int[n];
    static void push(){
        System.out.println("Enter data");
        int data=s.nextInt();
        if(top==n-1){
            System.out.println("stack is full");
        }
        else{
            top++;
            stack[top]=data;
        }
    }
    static void pop(){
        int item;
        if(top==-1)
        {
            System.out.println("Stack Empty");
        }
        else{
            item=stack[top];
            top--;
            System.out.println("Popped element is "+item);
        }
        
    }
    static void peek()
    {
        if(top==-1)
        {
            System.out.println("Stack Empty");
        }
        else
        {
            System.out.println("Top most element is "+stack[top]);
        }
    }
    static void display(){
        System.out.println("Stack elements are : ");
        for(int i=top;i>=0;i--)
        {
            System.out.print(stack[i]+" ");
        }
        System.out.println();
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
