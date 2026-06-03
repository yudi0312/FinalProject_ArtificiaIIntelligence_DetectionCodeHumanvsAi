public class BrowserHistoryStack {
    private String[] history=new String[20];
    private int top=-1;

    public void visit(String url){ history[++top]=url; }
    public String back(){ return history[--top]; }

    public static void main(String[] args){
        BrowserHistoryStack b=new BrowserHistoryStack();
        b.visit("a.com"); b.visit("b.com");
        System.out.println(b.back());
    }
}