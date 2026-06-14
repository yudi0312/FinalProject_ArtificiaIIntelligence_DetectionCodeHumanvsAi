import java.util.*;
public class Main{
    
  class Node
{
    int data;
    Node next;
     Node previous;  
     
    Node(int data)
    {
        this.data=data;
        next=null;
    }
}
    
  Node head,tail=null;
  public void insertNode(int data) {  
        Node newNode = new Node(data);  
        if(head == null) {  
             head = tail = newNode;  
            head.previous = null;  
            tail.next = null;  
        }  
        else {  
            tail.next = newNode;  
             newNode.previous = tail;  
            tail = newNode;  
            tail.next = null;  
        }  
    }  
     void deleteFrontNode() {  
          if(head==null)
         {
             System.out.println("list is empty.");
         }
         else{
            if(head != tail) {  
                head = head.next;  
                head.previous= null;  
            }  
            else {  
                head = null;  
                tail=null;
            }  
        }  
    }  
    public  void show()
    {
        Node temp=head;
        while(temp!=null)
        {
            System.out.println(temp.data);
            temp=temp.next;
        }
    }
     public static void main(String []args){
      Main ob=new Main();
      Scanner s1=new Scanner(System.in);
      ob.insertNode(10); 
      ob.insertNode(20);
      ob.insertNode(30); 
      ob.insertNode(40);
      ob.insertNode(50);
     System.out.println("the initial Linked List is");
      ob.show();
      ob.deleteFrontNode();
       System.out.println("the linked list after deletion from end: ");
       ob.show();
       
    
     }}

