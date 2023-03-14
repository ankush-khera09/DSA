import java.util.*;

public class StackUsingCollections{

    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        
        Stack<Integer> stk = new Stack<>();

        stk.push(1);
        stk.push(2);

        while(!stk.isEmpty()){
            System.out.println(stk.peek());
            stk.pop();
        }
    }
}