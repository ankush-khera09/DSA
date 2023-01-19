#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int* prefix_table(string pat){
    int m = pat.length();
    int* table = new int[m];
    table[0] = 0;

    int j=0;
    int i=1;

    while(i<m){
        if(pat[i]==pat[j]){
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

vector<int> kmpAlgo(string str, string pat){
    int n = str.length();
    int m = pat.length();

    int* lps = prefix_table(pat);

    vector<int> v;
    int i=0, j=0;

    while(i<n){
        if(str[i]==pat[j]){
            i++;
            j++;
        }

        if(j==m){
            v.push_back((i-j)+1);
            j = lps[j-1];
        }
        else if(i<n && str[i] != pat[j]){
            if(j!=0) j=lps[j-1];
            else i++;
        }
    }

    return v;
}


int main(){
    string str = "abcabcabcd";
    string pat = "abc";

    vector<int> v = kmpAlgo(str, pat);

    for(int i=0; i<v.size(); i++) cout<<v[i]<<" "<<endl;

    return 0;
}