public class PostfixEvaluation {
    public static int evaluate(){
        int[] s=new int[10];
        int top=-1;
        s[++top]=2; s[++top]=3;
        int b=s[top--]; int a=s[top--];
        s[++top]=a+b;
        return s[top];
    }
    public static void main(String[] args){
        System.out.println(evaluate());
    }
}