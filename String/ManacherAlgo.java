// This algorithm is used to find the length of longest palindromic substring

import java.util.*;

public class ManacherAlgo{
    
    public static String manacher(String s){
        int n = s.length();
        char[] newStr = new char[2*n+1];   // char array fot storing string like: #A#B#C#
        
        newStr[0] = '#';
        int k = 0;
        for(int i=1; i<2*n+1; i++){
            if(i%2==0) newStr[i]='#';
            else newStr[i]=s.charAt(k++);
        }

        int p[] = new int[2*n+1];      // longest palindromic centered at i
        int centre = 0, right = 0;
        int longestLength = 0, longestCentre = 0;   // for our longest palin substr

        for(int i=0; i<newStr.length; i++){
            int mirror = 2*centre-i;

            if(right>i){
                p[i] = Math.min(p[mirror], right-i);
            }
            // jha tak mil gyi hai palin, uske aage se dekhna h left/right side
            int a = i+(p[i]+1);     // to move along right 
            int b = i-(p[i]+1);     // to move along left

            while(b>=0 && a<newStr.length && newStr[a]==newStr[b]){
                b--;
                a++;
                p[i]++;    // incrementing value at i as we are finding longer palin
            }

            // updating our longest palin substr
            if(p[i] > longestLength){
                longestCentre = i;
                longestLength = p[i];
            }

            // if our window expands beyond right => we have found a longer palin
            if(i+p[i] > right){
                centre = i;
                right = i+p[i];
            }
        }

        String st = new String(newStr);        // take this char arr in a string
        return st.substring(longestCentre-longestLength, longestCentre+longestLength).replace("#", "");
        // returning our longest palin after replacing all "#" with nothing ""
    }


    // Naive's Approach-----------------------------------------------------------
    public static String naive(String s){
        int start=0, end=0;       // start & end of our palindromic substring
        for(int i=0; i<s.length(); i++){
            int odd = expand(s, i, i);         // checking for odd len substr, centre will be i only
            int even = expand(s, i, i+1);      // checking for even len substr, centre= i to i+1

            int len = Math.max(odd, even);          // will choose max length
            
            // checking if our curr len > previous len (can get by end-start)
            // if len > previous len => update start & end
            if(len > end-start){
                start = i-(len-1)/2;
                end = i+len/2;
            }
        }
        return s.substring(start, end+1);     // end+1 => to include end also
    }

    // to find len of palindromic substring (even/odd length)
    public static int expand(String s, int left, int right){
        while(left>=0 && right<s.length() && s.charAt(left)==s.charAt(right)){
            left--;
            right++;
        }
        return right-left-1;          // return len of palindromic substr
    }
    public static void main(String args[]) {
        String s = "babad";
        // System.out.println(naive(s));
        System.out.println(manacher(s));
    }
}