public class QueueScheduling {
    static class Job{
        String name;
        Job(String n){name=n;}
    }

    public static void main(String[] args){
        Job[] queue={new Job("A"),new Job("B"),new Job("C")};
        for(Job job:queue){
            System.out.println("Running "+job.name);
        }
    }
}