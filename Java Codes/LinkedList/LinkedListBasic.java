package LinkedList;
import java.util.*;

public class LinkedListBasic{

    Node head;
    private int size;

    LinkedListBasic(){
        this.size = 0;
    }

    class Node{
        String data;
        Node next;

        Node(String data){
            this.data = data;
            this.next = null;
        }
    }

    public void addFirst(String data){
        Node newNode  = new Node(data);

        // if LL is empty
        if(head==null){
            head = newNode;
            size++;
            return;
        }

        newNode.next = head;
        head = newNode;

        size++;
    }

    public void addLast(String data){
        Node newNode = new Node(data);

        // if LL is empty
        if(head==null){
            head = newNode;
            return;
        }

        Node p = head;
        while(p.next != null){
            p = p.next;
        }

        p.next = newNode;

        size++;
    }

    public void printList(){
        if(head==null) System.out.println("List is empty!");
        
        Node p = head;
        while(p != null){
            System.out.print(p.data+" ");
            p = p.next;
        }

        System.out.println();
    }

    public void deleteFirst(){
        if(head == null){
            System.out.println("List is already empty!");
            return;
        }

        head = head.next;
        size--;
    }

    public void deleteLast(){
        if(head == null){
            System.out.println("List is already empty!");
            return;
        }

        if(head.next == null){
            head = null;
            size--;
            return;
        }
        
        Node p = head;
        Node q = null;           // tail pointer
        while(p.next != null){
            q = p;
            p = p.next;
        }
        q.next = null;
        size--;
    }

    public int getSize(){
        return size;
    }

    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        LinkedListBasic ll = new LinkedListBasic();

        ll.addFirst("a");
        ll.addFirst("is");
        ll.addFirst("this");
        ll.addLast("list");
        ll.printList();

        ll.deleteFirst();
        ll.printList();

        ll.deleteLast();
        ll.printList();

        System.out.println(ll.getSize());
        
    }
}