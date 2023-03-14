package LinkedList;
import java.util.*;

public class LinkedListCollections{

    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        
        // LinkedList using Collections framework : -----------------------------------------

        LinkedList<String> ll = new LinkedList<String>();

        ll.addFirst("a");
        ll.addFirst("is");
        ll.addFirst("this");
        System.out.println(ll);

        ll.addLast("list");      // add() == addLast()
        System.out.println(ll);

        System.out.println(ll.size());

        for(int i=0; i<ll.size(); i++){
            System.out.print(ll.get(i)+" ");
        }
        System.out.println();

        ll.removeFirst();
        System.out.println(ll);
        ll.removeLast();
        System.out.println(ll);

        ll.remove(1);      // passing index
        System.out.println(ll);
    }
}