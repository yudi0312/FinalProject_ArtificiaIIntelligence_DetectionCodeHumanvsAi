import java.util.*;
public class Main
{  public static int top=-1;
public static int c=0;
    void push(char []stack,int n,char data){
        if(top>=n)
        {
           System.out.println("Stack overflow");}
        else
        {   top=top+1;
            stack[top]=data;}
    }
     void pop(char stack[],char item)
    {
        if(top<=-1){
            System.out.println("Stack Underflow");
        }
        else{
            item=stack[top];
            top--;}
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
           if(ch[i]=='{'||ch[i]=='('||ch[i]=='[')
           {ob.push(stack,k,ch[i]);}
           
           else if((ch[i]=='}'||ch[i]==']'||ch[i]==')' )&& (top>=0))
           {
               if ( ( stack[top] == '{' && ch[i]== '}')
						||(stack[top] == '(' && ch[i] == ')')
						|| (stack[top] == '[' && ch[i] == ']'))
				{
					ob.pop(stack,ch[i]);
                }
                else{
                    System.out.println("Invalid Inputs.");
                    c++;
                    break;
                }
           }
            else { 
                if ((ch[i] == ']' || ch[i] == '}' || ch[i] == ')')) {
                    c++;
                System.out.println("Invalid Inputs.");
                break;
            }
                
            }
        
       }
       if(c==0){
           System.out.println("Valid Inputs");
           
       }

       
      
	}
}
