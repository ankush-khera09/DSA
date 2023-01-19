#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

class Queue{
    private:
        Node* front;
        Node* rear;
    public:
        Queue(){
            this->front = this->rear = NULL;
        }

        int isEmpty(){
            if(front==NULL) return 1;
            return 0;
        }

        int isFull(){
            Node* t = new Node;
            if(t==NULL) return 1;
            return 0;
        }

        void enqueue(int x){
            Node* t = new Node;
            if(t==NULL) cout<<"Queue Overflow!"<<endl;
            else{
                t->data = x;
                t->next = NULL;
                // if it is the first node
                if(front==NULL) front = rear = t;
                else{
                    rear->next = t;
                    rear = t;
                }
            }
        }

        int dequeue(){
            int x = -1;
            Node* p;
            if(isEmpty()) cout<<"Queue Underflow!"<<endl;
            else{
                p = front;
                front=front->next;
                x = p->data;
                delete p;
            }
            return x;
        }

        void display(){
            Node* p = front;
            while(p!=NULL){
                cout<<p->data<<" ";
                p=p->next;
            }
            cout<<endl;
        }
};

int main(){
    int arr[] = {1,2,3,4,5};

    Queue q;

    for(int i=0; i<5; i++){
        q.enqueue(arr[i]);
    }

    q.display();

    cout<<"isEmpty: "<<q.isEmpty()<<endl;
    cout<<"isFull: "<<q.isFull()<<endl;

    q.dequeue();
    q.display();

    return 0;
}