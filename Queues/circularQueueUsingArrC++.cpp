#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Queue{
    private:
        int size;
        int front, rear;
        int *q;
    public:
        Queue(int size){
            this->size = size;
            this->front = this->rear = 0;
            this->q = new int[size];
        }

        int isEmpty(){
            if(front==rear) return 1;
            return 0;
        }

        int isFull(){
            if((rear+1)%size == front) return 1;
            return 0;
        }

        void display(){
            int i = front+1;
            do{
                cout<<q[i]<<" ";
                i = (i+1)%size;
            }while(i != (rear+1)%size);
            cout<<endl;
        }

        void enqueue(int x){
            if(isFull()) cout<<"Queue is Full!"<<endl;
            else{
                rear = (rear+1)%size;
                q[rear] = x;
            }
        }

        int dequeue(){
            int x = -1;
            if(isEmpty()) cout<<"Queue is Empty!"<<endl;
            else{
                front = (front+1)%size;
                x = q[front];
            }
            return x;
        }
};

int main(){
    
    int a[] = {1,2,3,4,5};

    Queue q(sizeof(a)/sizeof(a[0])+1);

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