#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};

void Ilast(Node* &head, int x){
    Node *p = head;
    Node *t = new Node;
    t->data = x;
    t->next = NULL;

    if(p==0){
        head = t;
    }else{
        while(p->next){
            p=p->next;
        }
        p->next = t;
        p=t;
    }
}

void display(Node *p){
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
}

// Node* merge(Node *p, Node *q){
//     Node *third=NULL, *last=NULL;

//     if(p==0 && q==0) return NULL;
//     else if(p==0) return q;
//     else if(q==0) return p;

//     if(p->data < q->data){
//         third = last = p;
//         p=p->next;
//         last->next = NULL;
//     }else{
//         third = last = q;
//         q=q->next;
//         last->next = NULL;
//     }
    
//     while(p && q){
//         if(p->data < q->data){
//             last->next = p;
//             last = p;
//             p=p->next;
//             last->next = NULL;
//         }else{
//             last->next = q;
//             last = q;
//             q=q->next;
//             last->next = NULL;
//         }
//     }

//     if(p!=0) last->next = p;
//     else last->next = q;

//     return third;
    
// }
                                                             // Using Dummy Node:
Node* merge(Node *p, Node*q){
    Node *dummy = new Node;
    dummy->data = -1;
    Node *last = dummy;

    while(p&&q){
        if(p->data < q->data){
            last->next = p;
            last = p;
            p=p->next;
        }else{
            last->next = q;
            last = q;
            q=q->next;
        }
    }

    if(p) last->next = p;
    else last->next = q;

    return dummy->next;
}

int main(){
    
    int t;
    cin>>t;

    while(t--){
        int m, n;
        Node *first = NULL;
        Node *second = NULL;
        cin>>m;
        while(m--){
            int x;
            cin>>x;
            Ilast(first, x);
        }
        display(first);
        cout<<endl;
        cin>>n;
        while(n--){
            int x;
            cin>>x;
            Ilast(second, x);
        }
        display(second);
        cout<<endl;

        Node *ans = NULL;
        ans = merge(first, second);
        display(ans);
    }

    return 0;
}