package com.threads;

import java.util.Random;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;

public class App {
 
 private static BlockingQueue<Integer> blockingQueue = new ArrayBlockingQueue<>(10);
 
 public static void main(String[] args) throws InterruptedException {
  
  //producer thread
  Thread t1 = new Thread(new Runnable() {
   
   @Override
   public void run() {
    try {
     producer();
    } catch (InterruptedException e) {
     e.printStackTrace();
    }
   }
  });
  
  //consumer thread
  Thread t2 = new Thread(new Runnable() {
   
   @Override
   public void run() {
    try {
     consumer();
    } catch (InterruptedException e) {
     e.printStackTrace();
    }
   }
  });
  
  //both these threads have a while loop so they will continue running indefinitely
  t1.start();
  t2.start();
  
  //waits for this thread to die. 
  t1.join();
  t2.join();
  
 }
 
 //sleep for random amount of time between 0-200 miliseconds and then add an item to the blocking queue
 private static void producer() throws InterruptedException {
  
  Random random = new Random();
  
  while(true) {

   //blockingQueue.put can cause InterruptedException
   Thread.sleep(random.nextInt(200));
   
   blockingQueue.put(random.nextInt(100));
  }
  
 }

 //sleep for random amount of time between 0-50 miliseconds and then take an item from the blocking queue
 private static void consumer() throws InterruptedException {
  
  Random random = new Random();
  
  while(true) {
   
   Thread.sleep(random.nextInt(50));
   
   if(random.nextInt(5) == 0) {

    Integer val = blockingQueue.take();
    System.out.println("Taken: " + val + "; Queue Size: " + blockingQueue.size());

   }
   
  }
  
 }
}
