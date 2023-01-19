#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node
{
    public:
    string data;
    Node *next;
};

void sol(int n){
    if(n>1000)
    {
        cout<<"No input given"<<endl;
        return ;
    }
    
    else if(n>10000)
    {
        cout<<"Input Exceeds the limit"<<endl;
        return ;
    }
    
    
    string arr[]={"1/2","1/3","1/4"};
    
    Node* tower1 = NULL;
    Node* tower2 = NULL;
    Node* tower3 = NULL;
    Node* tower4 = NULL;
    Node* tower5 = NULL;
    Node* tower6 = NULL;
  
  
    tower1 = new Node();
    tower2 = new Node();
    tower3 = new Node();
    tower4 = new Node();
    tower5 = new Node();
    tower6 = new Node();
    
    srand(time(NULL));
    tower1->data=arr[rand()%3];
    tower1->next=tower2;
    
    tower2->data=arr[rand()%3];
    tower2->next=tower3;
    
    tower3->data=arr[rand()%3];
    tower3->next=tower4;
    
    tower4->data=arr[rand()%3];
    tower4->next=tower5;
    
    tower5->data=arr[rand()%3];
    tower5->next=tower6;
    
    tower6->data=arr[rand()%3];
    tower6->next=NULL;
    
    Node *temp =tower1;
    
    int i=1;
    vector<int>req;
    while(temp!=NULL)
    {
        cout<<"Tower "<<i<<": "<<temp->data<<" of 500MW"<<endl;
        if(temp->data == "1/4"){
            req.push_back(i);
        }
        i++;
        temp=temp->next;
    }
    
    for(auto x:req){
        cout<<"Tower "<<x<<" Needs Maintenance"<<endl;
        
    }
    return ;
    
}
int main()
{
    sol(1000);
    return 0;
}