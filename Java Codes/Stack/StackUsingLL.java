package Stack;
import java.util.*;

public class StackUsingLL{
    
    static class Node{
        int data;
        Node next;

        Node(int data){
            this.data = data;
            this.next = null;
        }
    }

    static class Stack{
        static Node top;      // head of LL

        Stack(){
            top = null;
        }

        public static boolean isEmpty(){
            return top==null;
        } 

        public static void push(int data){
            Node newNode = new Node(data);
            if(newNode==null) System.out.println("Stack Overflow!");
            else{
                top = newNode;
            }
        }

        public static int pop(){
            int x = -1;

            if(isEmpty()) System.out.println("Stack Underflow!");
            else{
                x = top.data;
                top = top.next;
            }
            
            return x;
        }

        // peek() => top.data
        public static int peek(){
            if(top!=null) return top.data;
            else return -1;
        }
    }

    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        
        Stack stk = new Stack();

        System.out.println(stk.isEmpty());

        stk.push(1);
        stk.push(2);
        System.out.println(stk.isEmpty());

        System.out.println(stk.pop());
    }
}