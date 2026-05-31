public class ArrayDeque<Item> implements Deque<Item> {
    private int front;
    private int back;
   // private int nextFront;
    //private int nextBack;


    private Item[] arr;
    private int size;

    private boolean frontAdded;
    private boolean backAdded;

    public ArrayDeque(){
        arr = (Item[]) new Object[8];
        this.front=arr.length/2;
        this.back=front+1;
       // this.nextFront=front;
        //this.nextBack=front;
        this.size=0;

        this.frontAdded=false;
        this.backAdded=false;
    }

    public void addFirst(Item item){

        if(size==arr.length){
            enlarge();
        }



        if(frontAdded==false){

            arr[front]=item;
            frontAdded=true;

        }else{




            front=minusOne(front);
            arr[front]=item;

        }




        size++;



        if(size==arr.length && backAdded==false){
            back=minusOne(back);
            backAdded=true;
        }




    }


    public void addLast(Item item){

        if(size==arr.length){
            enlarge();
        }


        if(backAdded==false){

            arr[back]=item;
            backAdded=true;

        }else{



            back=addOne(back);
            arr[back]=item;

        }

        size++;

        if(size==arr.length && frontAdded==false){
            front=addOne(front);
            frontAdded=true;
        }


    }

    public boolean isFull(){
        return size==arr.length;
    }

    public int addOne(int index){
        index=index+1;
        return index%arr.length;
    }

    public int minusOne(int index){
        index=index-1;
        if(index<0){
            index=arr.length-1;
        }

        return index;
    }

    public boolean isEmpty(){
        return size==0;
    }


    public Item removeFirst(){


        //to remove,testing only
        //arr[front]=null;

        if(size==0){
            return null;
        }




        Item result=null;
        if(size==1){
            if(frontAdded==true){
                frontAdded=false;
                size--;
                return arr[front];
            }else{
                backAdded=false;
                size--;
                return arr[back];
            }

        }else{


            if(frontAdded==false){
                front=addOne(front);
                frontAdded=true;
            }



            result=arr[front];
            size--;
            if(size!=1){
                front=addOne(front);
            }else{
                frontAdded=false;

            }




        }

        return result;
    }

    public Item removeLast(){

        //to remove,testing only
        //arr[back]=null;
        if(size==0){
            return null;
        }




        Item result=null;
        if(size==1){
            if(frontAdded==true){
                frontAdded=false;
                size--;
                return arr[front];
            }else{
                backAdded=false;
                size--;
                return arr[back];
            }

        }else{

            if(backAdded==false){
                back=minusOne(back);
                backAdded=true;
            }


            result=arr[back];
            size--;
            if(size!=1){
                back=minusOne(back);
            }else{
                backAdded=false;

            }



        }
        return result;
    }


    public void printDeque(){
        int n=size;
        int start=-1;

        if(frontAdded==false){
            start=addOne(front);
        }else{
            start=front;
        }

        while(n!=0){
            System.out.print(arr[start%size].toString()+" ");
            n--;
            start=addOne(start);
        }
    }


    public void enlarge(){
        Item[] temp=(Item[]) new Object[size*2];
        int index=front;
        int i=0;
        int count=size;

        while(count!=0){
            temp[i]=arr[index];
            index=addOne(index);
            i=addOne(i);
            count--;
        }

        arr=temp;

        front=0;
        back=size-1;
    }



    public int size(){
        return size;
    }


    public Item get(int index){
        if(index<0 ||index>=size){
            return null;
        }

        int fakeFront=-1;

        if(frontAdded==false){
            fakeFront=addOne(front);
        }else{
            fakeFront=front;

        }


        return arr[(fakeFront+index)%size];
    }
}
