public class UndoRedoStack {
    private String[] undo=new String[20];
    private String[] redo=new String[20];
    int u=-1,r=-1;

    public void doAction(String a){ undo[++u]=a; }
    public void undo(){ redo[++r]=undo[u--]; }

    public static void main(String[] args){
        UndoRedoStack s=new UndoRedoStack();
        s.doAction("Edit");
        s.undo();
    }
}