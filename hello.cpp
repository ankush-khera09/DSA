#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int sub(vector<int> nums, int k){
    int sum = 0;
    int minlen = INT_MAX;
    deque<pair<int,int>> dq;

    for(int i=0; i<nums.size(); i++){
        sum+=nums[i];
        if(sum>=k){
            minlen = min(minlen,i+1);
        }

        pair<int, int> curr = {INT_MIN, INT_MIN};
        while(!dq.empty() && sum-dq.front().second >=k){
            curr = dq.front();
            dq.pop_front();
        }

        if(curr.second != INT_MIN){
            minlen = min(minlen, i-curr.first);
        }

        while(!dq.empty() && sum>=dq.back().second){
            dq.pop_back();
        }
        dq.push_back({i, sum});
    }
    return minlen==INT_MAX?-1:minlen;
}




int main(){
    

    return 0;
}