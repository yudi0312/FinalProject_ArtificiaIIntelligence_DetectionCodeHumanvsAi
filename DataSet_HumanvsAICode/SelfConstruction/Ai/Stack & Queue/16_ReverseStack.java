public class ReverseStack {
    public static void main(String[] args){
        int[] stack={1,2,3};
        for(int i=0;i<stack.length/2;i++){
            int t=stack[i];
            stack[i]=stack[stack.length-1-i];
            stack[stack.length-1-i]=t;
        }
    }
}