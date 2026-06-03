public class StackUsingTwoQueues {
    private int[] q1=new int[20];
    private int size=0;

    public void push(int v){ q1[size++]=v; }
    public int pop(){ return q1[--size]; }

    public static void main(String[] args){
        StackUsingTwoQueues s=new StackUsingTwoQueues();
        s.push(7);
        System.out.println(s.pop());
    }
}