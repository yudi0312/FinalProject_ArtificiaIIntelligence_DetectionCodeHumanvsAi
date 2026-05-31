    //****************************************Linked List Class*******************************

   public class LinkedList<T> {

Node<T> head;
T data;


public LinkedList(){
   head = null;
   }




public void add(T data){

    Node<T> newNode = new Node<T> (data);
    newNode.setLink(head);
    head = newNode;
}


  //had problems printing out the data in the last node

 public void traverse(){
    Node<T> pointer;
    pointer = head;

while (pointer.getLink()!=null){
        System.out.println(pointer.getData());
        pointer = pointer.setLink(pointer.getLink());
}

//Fixed problems For last node that doesnt get printed out
System.out.println(pointer.getData());

}
