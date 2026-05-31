import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class ReverseQueues {
    
    //create a queue function using return function of a queue and a parameter with queue
    public static  Queue<String> revQueue(Queue<String> que) {
        Stack<String> sk = new Stack<>();
        int a = que.size();

        for (int i = 0; i < a; i++) {
            sk.push(que.remove());
        }

        while (!sk.isEmpty()) {
            que.add(sk.pop());
        }

        System.out.print("This is when we put all the elements into reverse: ");
        return que;
    }

    public static void main(String[] args) {
        Queue<String> Q = new LinkedList<>();

        Q.add("Cars");
        Q.add("Trucks");
        Q.add("Airplanes");
        Q.add("Boats");

        System.out.println("Original elements in the Queues: " + Q);
        System.out.println();
        System.out.println(revQueue(Q));
    }
}
