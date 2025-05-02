#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void create(int arr[], int n)
{                                                           // Creating a circular LL
    struct Node *temp, *last;

    first = new Node;
    first->data = arr[0];
    first->next = first;
    last = first;

    for (int i = 1; i < n; i++)
    {
        temp = new Node;
        temp->data = arr[i];
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
}

void display(struct Node *p)
{
    do
    {                                                      // Printing Circular LL
        cout << p->data << " ";
        p = p->next;
    } while (p != first);
}

void recDisplay(struct Node *p)
{
    static int flag = 0;                                   // Printing Circular LL Recursively
    if (p != first || flag == 0)
    {
        cout << p->data << " ";
        recDisplay(p->next);
    }
    flag = 0;
}

int count(struct Node *p)
{
    int c = 0;                                            // Length of LL
    do
    {
        c++;
        p = p->next;
    } while (p != first);
    return c;
}

void Insert(struct Node *p, int index, int x)
{
    if (index < 0 || index > count(p)) return;           // Insert new node in circular LL

    struct Node *t;

    if (index == 0)
    {
        t = new Node;
        t->data = x;

        if (first == NULL)
        {
            first = t;
            first->next = first;
        }
        else
        {
            while (p->next != first)
                p = p->next;
            p->next = t;
            t->next = first;
            first = t;
        }
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
            p = p->next;
        t = new Node;
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}

int delNode(struct Node *p, int index){
    struct Node *q = NULL;                           // Deleting Node in circluar LL
    int x = -1;

    if(index<1 || index>count(p)) return -1;
    
    if(index==1){
        while(p->next!=first) p=p->next;
        x = first->data;
        if(p==first){
            delete first;
            first = NULL;
        }else{
            p->next = first->next;
            delete first;
            first = p->next;
        }
    }else{
        for(int i=0; i<index-1; i++){
            q=p;
            p=p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
        p = q->next;
    }
    return x;
}

//////////////////////////////////

void reverseCirLL(struct Node* p){                // Reversing a Circular LL
    struct Node *q=NULL, *r=NULL;
    do{
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }while(p!=first);
    p->next = q;
    first = q;
}

//////////////////////////////////

struct DNode{
    struct DNode *prev;            // Doubly LL Structure Node
    int val;
    struct DNode *next;
}*head = NULL;

void Dcreate(int arr[], int n){
    struct DNode *temp, *last;               // Creating Doubly LL

    head = new DNode;
    head->val = arr[0];
    head->prev = NULL;
    head->next = NULL;
    last = head;

    for(int i=1; i<n; i++){
        temp = new DNode;
        temp->val = arr[i];
        temp->next = last->next;
        temp->prev = last;
        last->next = temp;
        last = temp;
    }
}

void Ddisplay(struct DNode *p)
{
    while (p != 0){                                  // Printing Doubly LL
        cout << p->val << " ";
        p = p->next;
    }
}

int Dcount(struct DNode *p)
{
    int c = 0;                       // Length of Doubly LL
    while (p != 0){
        c++;
        p = p->next;
    }
    return c;
}

void Dinsert(struct DNode *p, int index, int x){
    if(index<0 || index>Dcount(p)) return;      // Inserting node in doubly LL

    struct DNode *temp = new DNode;
    temp->val = x;

    if(index == 0){
        temp->next = head;
        temp->prev = NULL;
        head->prev = temp;
        head = temp;
    }else{
        for(int i=0; i<index-1; i++) p=p->next;
        temp->prev = p; 
        temp->next = p->next;
        if(p->next) p->next->prev = temp;
        p->next = temp;
    }
}

int DdelNode(struct DNode *p, int index){
    if(index<=0 || index>Dcount(p)) return -1;
    int x = -1;                                    // Deleting node from doubly LL

    if(index==1){
        head = head->next;
        x = p->val;
        delete p;
        if(head) head->prev = NULL;
    }else{
        for(int i=0; i<index-1; i++) p=p->next;
        p->prev->next = p->next;
        if(p->next) p->next->prev = p->prev;
        x = p->val;
        delete p;
    }
    return x;
}

void Dreverse(struct DNode *p){
    struct DNode *temp;                                      // Reversing a doubly LL
    while(p){
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;

        if(p!=0 && p->next == NULL) head = p;
    }
}

int main(){

    int arr[] = {1, 2, 3, 4, 5};
    create(arr, 5);
    display(first);
    cout << endl;

    cout << "No of Nodes: " << count(first) << endl;

    // Insert(first, 3, 100);
    // display(first);
    // cout<<endl;

    // cout<<"Deleted element: "<<delNode(first, 8);
    // cout<<endl;
    // display(first);

    Dcreate(arr, 5);
    Ddisplay(head);
    cout<<endl;

    // Dinsert(head, 4, 100);
    // Ddisplay(head);

    // cout<<DdelNode(head, 0)<<endl;
    // Ddisplay(head);

    Dreverse(head);
    Ddisplay(head);

    return 0;
}