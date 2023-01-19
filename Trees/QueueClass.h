#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        Node *lchild;        // left child
        int data;
        Node *rchild;        // right child
};

class Queue{
    
    private:
        int size;
        int front, rear;
        Node **q;             // one * is for array of pointers & other is for Node*
        // [Node*]*: Pointer to [Pointer to Node]
    public:
        Queue(int size){
            this->size = size;
            this->front = this->rear = -1;
            this->q = new Node*[size];
        }

        void enqueue(Node* x){
            if(rear==size-1) cout<<"Queue is Full!"<<endl;
            else{
                rear++;
                q[rear] = x;
            }
        }

        Node* dequeue(){
            Node* x = NULL;
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