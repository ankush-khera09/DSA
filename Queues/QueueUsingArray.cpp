#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Queue{
    
    private:
        int size;
        int front, rear;
        int* q;
    
    public:
        Queue(int size){
            this->size = size;
            this->front = this->rear = -1;
            this->q = new int[size];
        }

        void enqueue(int x){
            if(rear==size-1) cout<<"Queue is Full!"<<endl;
            else{
                rear++;
                q[rear] = x;
            }
        }

        void display(){
            for(int i=front+1; i<=rear; i++) cout<<q[i]<<" ";
            cout<<endl;
        }

        int dequeue(){
            int x = -1;
            if(front==rear) cout<<"Queue is empty!"<<endl;
            else{
                front++;
                x = q[front];
            }
            return x;
        }

        int isFull(){
            if(rear==size-1) return 1;
            return 0;
        }

        int isEmpty(){
            if(front==rear) return 1;
            return 0;
        }
};

int main(){
    
    int a[] = {1,2,3,4,5};

    Queue q(5);

    for(int i=0; i<5; i++){
        q.enqueue(a[i]);
    }

    q.display();

    cout<<"isEmpty: "<<q.isEmpty()<<endl;
    cout<<"isFull: "<<q.isFull()<<endl;

    q.dequeue();
    q.display();

    return 0;
}