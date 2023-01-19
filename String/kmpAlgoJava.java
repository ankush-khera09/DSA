import java.util.*;

public class kmpAlgoJava {

    public static int[] prefix_table(String pat){
        int m = pat.length();
        int table[] = new int[m];
        table[0] = 0;

        int j=0, i=1;

        while(i<m){
            if(pat.charAt(i) == pat.charAt(j)){
                j++;
                table[i] = j;
                i++;
            }else{
                if(j!=0){
                    j = table[j-1];
                }else{
                    table[i] = j;
                    i++;
                }
            }
        }

        return table;
    }

    public static ArrayList<Integer> kmpAlgo(String str, String pat){
        int n = str.length();
        int m = pat.length();

        int[] table = prefix_table(pat);

        ArrayList<Integer> ans = new ArrayList<>();
        int i=0, j=0;

        while(i<n){
            if(str.charAt(i) == pat.charAt(j)){
                i++;
                j++;
            }

            if(j==m){
                ans.add((i-j)+1);
                j = table[j-1];
            }
            else if(i<n && str.charAt(i) != pat.charAt(j)){
                if(j!=0) j=table[j-1];
                else i++;
            }
        }
        
        return ans;
    }

    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        String str = "abcabcabcd";
        String pat = "abc";

        ArrayList<Integer> ans = new ArrayList<>();
        ans = kmpAlgo(str, pat);

        for(int i=0; i<ans.size(); i++) System.out.print(ans.get(i)+" ");;
    }
}
