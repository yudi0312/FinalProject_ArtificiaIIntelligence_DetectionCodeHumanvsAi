public class MinStack {
    private int[] stack=new int[100];
    private int[] min=new int[100];
    private int top=-1;

    public void push(int v){
        stack[++top]=v;
        min[top]=(top==0)?v:Math.min(v,min[top-1]);
    }
    public int getMin(){ return min[top]; }

    public static void main(String[] args){
        MinStack s=new MinStack();
        s.push(5); s.push(2);
        System.out.println(s.getMin());
    }
}