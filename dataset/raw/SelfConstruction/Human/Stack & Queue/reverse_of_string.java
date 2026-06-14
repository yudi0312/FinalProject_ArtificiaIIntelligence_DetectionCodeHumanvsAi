import java.util.*;
public class Main
{  public int top=-1;
    void push(char []stack,int n,char data){
        if(top>=n-1)
        {
           System.out.println("Stack overflow");
        }
        else
        {   top=top+1;
            stack[top]=data;
        }
    }
     void pop(char stack[],char item)
    {
        if(top<=-1){
            System.out.println("Stack Underflow");
        }
        else{
            item=stack[top];
            top--;
            System.out.print(item+" ");
        }
    }
	public static void main(String[] args) {
        int data;
        Scanner s=new Scanner(System.in);
       String str=s.next();
       char ch[]=str.toCharArray();
       int k=str.length();
       char stack[]=new char[k];
        Main ob=new Main();
       for(int i=0;i<k;i++)
       {
           ob.push(stack,k,ch[i]);
       }
       System.out.println("Stack is : ");
       for(int i=0;i<k;i++)
       {
           System.out.println(stack[i]);
       }
        System.out.println("Reverse string is : ");
         for(int i=k-1;i>=0;i--)
       {
           ob.pop(stack,ch[i]);
       }
	}
}
