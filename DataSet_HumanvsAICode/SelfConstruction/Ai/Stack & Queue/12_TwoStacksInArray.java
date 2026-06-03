public class TwoStacksInArray {
    private int[] arr=new int[20];
    private int top1=-1, top2=20;

    public void push1(int v){ arr[++top1]=v; }
    public void push2(int v){ arr[--top2]=v; }

    public static void main(String[] args){
        TwoStacksInArray t=new TwoStacksInArray();
        t.push1(1); t.push2(9);
    }
}