
public class LinkedList {
    private int val;
    private LinkedList next;

    public LinkedList (int val, LinkedList next) {
        this.val = val;
        this.next = next;
    }

    public LinkedList (int val) {
        this(val, null);
    }

    public void print () {
        if (next != null) {
            System.out.print(val + " -> ");
            next.print();
        } else {
            System.out.println(val);
        }
    }

    public void print_reverse() {
        if (next != null) {
            next.print_reverse();
        } 
        System.out.print(val + " -> ");
    }

    public void insert_end (int val) {
        if (next == null) {
            next = new LinkedList(val);
        } else {
            next.insert_end(val);
        }
    }

    public static void main(String[] args) {
        LinkedList head = new LinkedList(10);
        for (int i = 0; i < 10; i ++)
            head.insert_end(i);
        head.print();
        // head.print_reverse();
    }
}