public class PriorityQueue {
    private int[] heap=new int[100];
    private int size=0;

    public void insert(int value){
        int i=size++; heap[i]=value;
        while(i>0){
            int p=(i-1)/2;
            if(heap[p] >= heap[i]) break;
            int t=heap[p]; heap[p]=heap[i]; heap[i]=t;
            i=p;
        }
    }
    public int removeMax(){
        int max=heap[0];
        heap[0]=heap[--size];
        return max;
    }
    public static void main(String[] args){
        PriorityQueue pq=new PriorityQueue();
        pq.insert(10); pq.insert(50);
        System.out.println(pq.removeMax());
    }
}