import java.util.*;

public class StackUsingArrayList{

    static class Stack{
        static ArrayList<Integer> list = new ArrayList<>();

        public static boolean isEmpty(){
            return list.size()==0;
        }

        public static void push(int data){
            list.add(data);
        }

        public static int pop(){
            if(isEmpty()) return -1;

            int top = list.get(list.size()-1);
            list.remove(list.size()-1);
            return top;
        }

        public static int peek(){
            if(isEmpty()) return -1;
            return list.get(list.size()-1);
        }
    }
    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        
        Stack stk = new Stack();

        stk.push(1);
        stk.push(2);
        stk.push(3);
        stk.push(4);
        stk.push(5);

        while(!stk.isEmpty()){
            System.out.println(stk.peek());
            stk.pop();
        }
    }
}