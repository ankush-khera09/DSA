#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;                                  // Node Structure
    struct Node *next;
}*first = NULL;

void create(int A[], int n){
    struct Node *temp, *last;                         

    first = new Node;                     // Creating first Node
    first->data = A[0];                     
    first->next = NULL;
    last = first;

    for(int i=1; i<n; i++){            // Creating nodes and linking them to make a LL
        temp = new Node;
        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }

}

void display(struct Node *p){           // Printing a LL
    while(p!=NULL){
        cout<<p->data<<" ";
        p = p->next;
    }
}

void recDisplay(struct Node *p){          // Printing LL Recursively
    if(p!=NULL){
        cout<<p->data<<" ";
        recDisplay(p->next);
    }
}

void recDisplayRev(struct Node *p){          // Printing LL Recursively in reverse order
    if(p!=NULL){
        recDisplayRev(p->next);
        cout<<p->data<<" ";
    }
}

int lenofll(struct Node *p){
    int count = 0;                          // Length of LL
    while(p!=NULL){
        count++;
        p = p->next;
    }
    return count;
}

int recLenofll(struct Node *p){
    int count = 0;                          // Length of LL Recursively
    if(p==0) return 0;
    else return recLenofll(p->next)+1;
}

int sumofll(struct Node *p){
    int sum = 0;
    while(p!=0){                          // Sum of elements of LL
        sum+=p->data;
        p = p->next;
    }
    return sum;
}

int recSumofll(struct Node *p){
    int sum = 0;                        // Sum of elements of LL Recursively
    if(p==0) return 0;
    else return recSumofll(p->next)+p->data;
}

int maxele(struct Node *p){
    int max = INT_MIN;                     // Maximum Element
    while(p!=0){
        if(p->data>max){
            max = p->data;
            p=p->next;
        }else{
            p=p->next;
        }
        
    }
    return max;
}

int recMaxEle(struct Node *p){
    int max = INT_MIN;                      // Maximum Element Recursively
    if(p==0) return INT_MIN;
    else{
        max = recMaxEle(p->next);
        if(max>p->data) return max;
        else return p->data;
    }
}

struct Node* linSearch(struct Node *p, int key){
    while(p!=0){
        if(key==p->data) return p;                 // Linear Search
        p=p->next;
    }
    return NULL;
}

struct Node* recLinSearch(struct Node *p, int key){
    if(p==NULL) return NULL;                      // Linear Search Recursively
    if(key==p->data) return p;
    return recLinSearch(p->next, key);
}

struct Node* ImprovedLinSearch(struct Node *p, int key){
    // using "MOVE TO HEAD" concept
    struct Node *q = NULL;
    while(p!=0){                                // Transposition in Linear Search
        if(key==p->data){
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        };
        q=p;
        p=p->next;
    }
    return NULL;
}

void Insert(struct Node *p, int index, int x){
    struct Node *t;
    if(index<0 || index>lenofll(p)) return;
                                                  // Inserting Nodes
    t = new Node;
    t->data = x;

    if(index==0){
        t->next = first;
        first = t;
    }else{
        for(int i=0; i<index-1; i++){
            p=p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

void InsertLast(int x){
    struct Node *t = new Node;
    t->data = x;
    t->next = NULL;                      // Creating a LL by inserting node at last

    if(first==NULL){
        first = t;
    }else{
        struct Node *last = first;
        while(last->next!=0){
            last=last->next;
        }
        last->next = t;
        last = t;
    }
}

void InsInSort(struct Node *p, int x){
    struct Node *t = new Node;             // Inserting Node in a sorted LL
    t->data = x;
    t->next = NULL;

    struct Node *q = NULL;

    if(first==NULL) first = t;
    else{
        while(p && p->data < x){
            q = p;
            p = p->next;
        }
        if(p==first){
            t->next = first;
            first = t;
        }else{
            t->next = p;
            q->next = t;
        }
    }
}

int deleteNode(struct Node *p, int index){
    struct Node *q = NULL;                           // Deleting Nodes
    int x = -1;

    if(index<1 || index>lenofll(p)) return -1;

    if(index==1){
        q = first;
        first=first->next;
        x = q->data;
        delete q;
    }else{
        for(int i=0; i<index-1; i++){
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        delete p;
    }
    return x;
}

bool checkSort(struct Node *p){
    int x = INT_MIN;                   // Check if a LL is sorted or not
    while(p!=0){
        if(p->data < x) return false;

        x = p->data;
        p = p->next;
    }
    return true;
}

void RemoveDupFromSortedLL(struct Node *p){
    struct Node *q = first->next;
    while(q!=0){                               // Remove Duplicates from sorted LL
        if(p->data!=q->data){
            p=q;
            q=q->next;
        }else{
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}

void revLL(struct Node *p){
    int n = lenofll(p);
    int temp[n] ={0};                 // Reversing elements of LL
    for(int i=0; i<n; i++){
        temp[i] = p->data;
        p=p->next;
    }
    // int i=0;
    // while(p!=NULL){
    //     temp[i++] = p->data;
    //     p=p->next;
    // }
    p=first;
    for(int i=n-1; i>=0; i--){
        p->data = temp[i];
        p=p->next;
    }
}

void revLinksLL(struct Node *p){
    struct Node *q=NULL, *r=NULL;
    while(p!=0){                   // Reverse LL by reversing links using 3 sliding pointers
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first = q;
}

void recRev(struct Node *q, struct Node *p){
    if(p!=0){                      // Recursive Reverse of LL by using 2 pointers
        recRev(p, p->next);
        p->next = q;
    }else{
        first = q;
    }
}

void concat(struct Node *p, struct Node *q){
    while(p->next != 0){            // concatenating 2 LL
        p=p->next;
    }
    p->next = q;
    // second = NULL;   // making head of 2nd LL NULL
}

struct Node* merge(struct Node *p, struct Node *q){
    struct Node *third=NULL, *last=NULL;
                                                  // Merge 2 sorted LL
    if(p==0 && q==0) return NULL;
    else if(p==0) return q;
    else if(q==0) return p;

    if(p->data < q->data){
        third=last=p;
        p=p->next;
        last->next = NULL;
    }else{
        third=last=q;
        q=p->next;
        last->next = NULL;
    }

    while(p!=0 && q!=0){
        if(p->data < q->data){
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }else{
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if(p!=0) last->next = p;
    else if(q!=0) last->next = q;

    return third;
}

bool isLoop(struct Node *p){
    struct Node *q = first;
    do{                                    // Check for loop in LL
        p = p->next;
        q = q->next;
        q = q==NULL?NULL:q->next;
    }while(p && q && p!=q);

    if(p==q) return true;
    else return false;
                                                // using while loop:
    // struct Node *p = head, *q = head;
    // if(head==NULL || head->next==NULL) return false;
    // while(p&&q){
    //     p=p->next;
    //     q=q->next;
    //     q= q==NULL?NULL:q->next;
    //     if(p==q) return true;
    // };
    
    // return false;
}

struct Node* middle(struct Node *p){
    int c = lenofll(p);                        // find middle node of the LL
    if(c%2==0) c=c/2;
    else c=(c/2)+1;

    for(int i=0; i<c-1; i++) p=p->next;
    return p;
}

int middle2(struct Node *p){
    struct Node *q = first;                       // Find Middle Node using 2 pointers
    while(q){
        q=q->next;
        if(q) q=q->next;
        if(q) p=p->next;
    }
    return p->data;
}


/*

LEETCODE QUE: Remove LL elements
eg: [1,2,6,3,4,5,6] val=6 (remove all 6)
eg: [7,7,7,7,7] val=7 (remove all 7)


ListNode* removeElements(ListNode* head, int val){
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    ListNode *p = dummy; 
    while(p && p->next){
        if(p->next->val == val){
            ListNode *temp = p->next;
            p->next = temp->next;
            delete temp;
        }else{
            p=p->next;
        }
    }

    return dummy->next;
}

*/


Node* RemoveElements(Node *p, int x){                   // Remove all occurences of x from LL
    Node *dummy = new Node;
    dummy->data = -1;
    dummy->next = p;

    Node* q = dummy;

    while(q && q->next){
        if(q->next->data == x){
            Node * temp = q->next;
            q->next = temp->next;
            delete temp;
        }else{
            q=q->next;
        }
    }
    
    return dummy->next;
}

// LEETCODE QUE
bool isPalindrome(struct Node* p) {
    string s="";                   // Checking if LL is Palindrome or not
                                    // Palindrome: 1221 == 1221 (on reversing)
    while(p){
        s+= to_string(p->data);
        p=p->next;
    }

    int low=0, high=s.length()-1;
    while(low<high){
        if(s[low]!=s[high]) return false;
        low++;
        high--;
    }
    return true;
}

/*

LEETCODE QUE: FIND INTERSECTION POINT OF 2 LL

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *p1 = headA;
    ListNode *p2 = headB;
    
    if(p1==0 || p2==0) return NULL;
    
    while(p1!=0 && p2!=0 && p1!=p2){
        p1=p1->next;
        p2=p2->next;
        
        if(p1==p2) return p1;
        
        if(p1==NULL) p1=headB;
        if(p2==NULL) p2=headA;
    }
    
    return p1;
}

*/


int main(){
    
    int A[] = {1,2,3,4,5};
    create(A, 5);

    display(first);
    cout<<endl;
    // recDisplay(first);
    // cout<<endl;
    recDisplayRev(first);
    cout<<endl;

    cout<<"Length of LL: "<<lenofll(first)<<endl;

    cout<<"Sum of elements: "<<sumofll(first)<<endl;

    cout<<"Max ele: "<<maxele(first)<<endl;

    cout<<"Linear Search: "<<linSearch(first, 3)<<endl;

    // Insert(first, 4, 100);
    // cout<<"Inserting new node: ";
    // display(first);
    // cout<<endl;

    // InsertLast(100);
    // display(first);

    // InsInSort(first, 3);
    // display(first);

    // cout<<"Deleted element: "<<deleteNode(first, 4)<<endl;
    // display(first);
    // cout<<endl;

    cout<<"Sorted or Not: "<<checkSort(first)<<endl;

    // RemoveDupFromSortedLL(first);
    // display(first);

    // recRev(NULL,first);
    // display(first);

    // int B[] = {6,7,8,9,10};

    // concat(first, second);
    // display(first);

    // merge(first, second);

    cout<<"Middle Node: "<<middle2(first)<<endl;

    // cout<<"Palindrome: "<<isPalindrome(first);

    // Node *p = RemoveElements(first, 2);
    // display(p);



    return 0;
}

