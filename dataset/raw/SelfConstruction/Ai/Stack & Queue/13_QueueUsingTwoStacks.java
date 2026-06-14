public class QueueUsingTwoStacks {
    private int[] s1=new int[20];
    private int[] s2=new int[20];
    int t1=-1,t2=-1;

    public void enqueue(int v){ s1[++t1]=v; }
    public int dequeue(){
        while(t1!=-1) s2[++t2]=s1[t1--];
        return s2[t2--];
    }
    public static void main(String[] args){
        QueueUsingTwoStacks q=new QueueUsingTwoStacks();
        q.enqueue(1); q.enqueue(2);
        System.out.println(q.dequeue());
    }
}