#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

class LinkedList{
    private:
        Node* first;
    public:
        LinkedList(){
            first = NULL;
        }
        LinkedList(int arr[], int n){
            Node *temp, *last;

            first = new Node;
            first->data = arr[0];
            first->next = NULL;
            last = first;

            for(int i=1; i<n; i++){
                temp = new Node;
                temp->data = arr[i];
                temp->next = NULL;
                last->next = temp;
                last = temp;
            }
        }

        void display(){
            Node *p = first;
            while(p){
                cout<<p->data<<" ";
                p=p->next;
            }
            cout<<endl;
        }

        int count();
};

int LinkedList::count(){
    int count = 0;
    Node *p = first;
    while(p){
        count++;
        p=p->next;
    }
    return count;
}

int main(){
    
    int arr[] = {1,2,3,4,5};
    LinkedList list1(arr, 5);

    list1.display();

    cout<<list1.count()<<endl;
    

    return 0;
}