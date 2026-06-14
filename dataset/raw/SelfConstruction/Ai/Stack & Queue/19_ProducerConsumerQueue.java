public class ProducerConsumerQueue {
    private int value;
    private boolean available=false;

    public synchronized void produce(int v){
        value=v; available=true; notify();
    }
    public synchronized int consume() throws InterruptedException{
        while(!available) wait();
        available=false;
        return value;
    }
}