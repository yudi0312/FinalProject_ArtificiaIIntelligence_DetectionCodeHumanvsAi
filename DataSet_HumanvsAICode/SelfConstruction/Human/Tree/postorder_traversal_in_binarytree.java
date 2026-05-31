import java.util.*;
public class Main
{
    public static Scanner s=new Scanner(System.in);
    Node head=null;
    static class Node{
        int data;
        Node left;
        Node right;
    
    Node(int item){
        data=item;
        left=null;
        right=null;
    }
    }
    static Node create()
    {
        int x;
        System.out.println("Enter Node Data (-1 for no Node)");
        x=s.nextInt();
        if(x==-1)
        {
            return null;
        }
         Node newnode=new Node(x);
        newnode.data=x;
        System.out.println("Enter Left Child of "+x);
        newnode.left=create();
        System.out.println("Enter Right Child of "+x);
        newnode.right=create();
        return newnode;
    }
    static void postorder(Node root)
    {
        if(root==null)
        {
            return ;
        }
        postorder(root.left);
        postorder(root.right);
        System.out.print(root.data+" ");
    }
	public static void main(String[] args) {
	
		Main ob=new Main();
    
      Node root=null;
      root=create();
      System.out.println("\nPostorder Traversal : ");
      postorder(root);
     
	 
	    
	}
}



