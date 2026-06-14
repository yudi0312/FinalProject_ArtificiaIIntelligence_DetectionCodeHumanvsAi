public class BalancedParentheses {
    public static boolean isBalanced(String s){
        char[] stack=new char[s.length()];
        int top=-1;
        for(char c:s.toCharArray()){
            if(c=='(') stack[++top]=c;
            else if(c==')'){
                if(top==-1) return false;
                top--;
            }
        }
        return top==-1;
    }
    public static void main(String[] args){
        System.out.println(isBalanced("(())"));
    }
}