#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int x){
            this->data = x;
            this->next = NULL;
        }
};

class LinkedList{
    public:
        Node* head;

        LinkedList(){
            head = NULL;
        }
        
        LinkedList(int arr[], int n){
            Node *temp, *last;              // temp for making a node & last will point to last node in LL
        
            head = new Node(arr[0]);              // making first node

            last = head;

            for(int i=1; i<n; i++){
                temp = new Node(arr[i]);           // Creating nodes and linking them to make a LL
                last->next = temp;
                last = temp;
            }
        }

        void display(Node* head);            // to print the LL
        void RecDisplay(Node* head);                  // Recursively
        void RecDisplayRev(Node* head);              // Recursively + print in reverse order

        int count(Node* head);                  // length of LL (no. of nodes in LL)
        int RecCount(Node* head);

        int sum(Node* head);                    // sum of all nodes
        int RecSum(Node* head);

        int maxEle(Node* head);                     // maximum element in LL
        int RecMaxEle(Node* head);

        Node* linearSearch(Node* head, int key);
        Node* RecLinearSearch(Node* head, int key);
        Node* ImprovedLinearSearch(Node* head, int key);         // using "MOVE TO HEAD" method

        void Insert(Node* head, int index, int ele);
        Node* InsertAtLast(Node* head, int ele);
        void InsertInSortedLL(Node* head, int ele);

        int deleteNode(Node** head, int index);

        bool checkSort(Node* head);

        void removeDuplicatesFromSortedLL(Node* head);

        void revLL(Node* head);
        Node* revLinksLL(Node* head);
        void recRev(Node* q, Node* p);

        void concat(Node* head1, Node* head2);

        Node* merge2LL(Node* p, Node* q);

        bool isLoop(Node* head);
        Node* startOfLoop(Node* head);
        void removeLoop(Node* head);

        Node* middle(Node* head);
        Node* middle2(Node* head);

        Node* IntersectionOfTwoLL1(Node* head1, Node* head2);
        Node* IntersectionOfTwoLL2(Node* head1, Node* head2);

        Node* removeLLElements1(Node* head, int val);
        Node* removeLLElements2(Node* head);
};

void LinkedList::display(Node* head){
    Node* p = head;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
}

void LinkedList::RecDisplay(Node* head){
    Node* p = head;
    if(p != NULL){
        cout<<p->data<<" ";
        RecDisplay(p->next);
    }
}

void LinkedList::RecDisplayRev(Node* head){
    Node* p = head;
    if(p){
        RecDisplayRev(p->next);
        cout<<p->data<<" ";
    }
}

int LinkedList::count(Node* head){
    Node* p = head;
    int count = 0;
    while(p){
        count++;
        p=p->next;
    }
    return count;
}

int LinkedList::RecCount(Node* head){
    Node* p = head;

    if(p==0) return 0;

    return count(p->next)+1;
}

int LinkedList::sum(Node* head){
    Node* p = head;
    int sum = 0;
    while(p){
        sum += p->data;
        p=p->next;
    }
    return sum;
}

int LinkedList::RecSum(Node* head){
    Node* p = head;
    if(p==0) return 0;
    return RecSum(p->next)+p->data;
}

int LinkedList::maxEle(Node* head){
    Node* p = head;
    int maxi = INT_MIN;
    while(p){
        if(p->data > maxi){
            maxi = p->data;
        }
        p=p->next;
    }
    return maxi;
}

int LinkedList::RecMaxEle(Node* head){
    if(head==NULL) return INT_MIN;
    
    return max(head->data, recMaxEle(head->next));
}

Node* LinkedList::linearSearch(Node* head, int key){
    Node* p = head;
    while(p){
        if(key == p->data) return p;
        p=p->next;
    }
    return NULL;                   // if key not found
}

Node* LinkedList::RecLinearSearch(Node* head, int key){
    Node* p = head;

    if(p==0) return NULL;
    if(p->data == key) return p;
    return RecLinearSearch(p->next, key);
}

Node* LinkedList::ImprovedLinearSearch(Node* head, int key){
    // Using "MOVE TO HEAD" method
    Node* p = head;
    Node* q = NULL;

    while(p){
        if(p->data == key){
            q->next = p->next;
            p->next = head;
            head = p;
            return p;
        }
        
        q=p;
        p=p->next;
    }
    return NULL;
}

void LinkedList::Insert(Node* head, int index, int ele){
    Node* p = head;
    
    if(index < 0 || index > count(head)) return;           // checking if index is valid

    Node* temp = new Node(ele);
    // inserting at first
    if(index==0){
        temp->next = head;
        head = temp;
    }else{
        // inserting in between
        for(int i=0; i<index-1; i++){
            p=p->next;
        }

        temp->next = p->next;
        p->next = temp;
    }

}

// Creating a LL by inserting node at last
Node* LinkedList::InsertAtLast(Node* head, int ele){
    Node* temp = new Node(ele);

    // if the LL is empty
    if(head==NULL) head = temp;
    else{
        // if the LL is not empty => move to last node of the LL
        Node* last = head;
        while(last->next != NULL) last = last->next;
        last->next = temp;
    }
    return head;     // return new updated head (this will help when LL is empty at first)
}

// Inserting Node in a Sorted LL
// passing head by ref as changing head inside won't reflect on main head otherwise
void LinkedList::InsertInSortedLL(Node *&head, int ele){
    Node *temp = new Node(ele);

    // if empty list or ele to be inserted at first
    if(head==NULL || ele <= head->data){
        temp->next = head;
        head = temp;
        return;
    }
    
    Node *p = head;
    while(p->next && p->next->data < ele) p = p->next;
    temp->next = p->next;
    p->next = temp;
}

// In C++, we can use [ Node* &head ] => this will be reference to the pointer
int LinkedList::deleteNode(Node* &head, int index){
    if(index<0 || index>=count(head)) return -1;

    Node* p = head;
    int x = -1;

    // if it is the first node
    if(index==0){
        head = head->next;
        x = p->data;
        delete p;
    }else{
        for(int i=0; i<index-1; i++) p=p->next;
        Node* q = p->next;    // node to be deleted
        p->next = p->next->next;
        x = q->data;
        delete q;
    }
    return x;
}

// we have used here **head as we are passing this pointer head as call by reference using pointer
// this is because when index==0, head node for this below function will be updated but the real head will
// remain same and will not reflect any change

// or without these Node** :  we can return updated head node from this function
int LinkedList::deleteNode(Node** head, int index){
    Node *p = *head;
    Node *q = NULL;

    int x = -1;

    if(index < 0 || index >= count(*head)) return -1;

    if(index==0){
        q = *head;
        *head = (*head)->next;
        x = q->data;
        delete q;
    }else{
        for(int i=0; i<index; i++){
            q = p;
            p = p->next;
        }
        q->next=p->next;
        x = p->data;
        delete p;
    }
    return x;
}

bool LinkedList::checkSort(Node* head){
    // empty list or single node is always sorted
    if(head==NULL || head->next==NULL) return true;
    
    while(head->next){
        if(head->data > head->next->data) return false;
        head=head->next;
    }
    return true;
}

void LinkedList::removeDuplicatesFromSortedLL(Node* head){
    while(head->next){
    if(head->data == head->next->data){
        Node* q = head->next;
        head->next = head->next->next;
        delete q;
    }else{
        // move only if no deletion because we can have multiple duplicates
        // 1 1 1 2 3 4
        // first duplicate remove hoga => 1 1 2 3 4 => head ko vhi rehne do taaki next bhi delete ho paaye
        head = head->next;
    }
}
}

void LinkedList::revLL(Node* head){
    int n = count(head);
    int arr[n];

    Node* p = head;
    int i = 0;
    while(p){
        arr[i++] = p->data;
        p=p->next;
    }

    p = head;
    for(int i=n-1; i>=0; i--){
        p->data = arr[i];
        p=p->next;
    }
}

Node* LinkedList::reverseLL(Node* head){
    Node *curr=head, *prev=NULL, *next=NULL;
    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node* LinkedList::revLinksLL(Node* head){
    // r => previous node
    // q => current node
    // p => next node
    Node *p = head;
    Node *q=NULL, *r=NULL;

    while(p){
        r = q;
        q = p;
        p = p->next;
        q->next = r;      // reversing link
    }
    return q;       // returning new head
}

Node* LinkedList::recursiveReverseLL(Node* head){
    // base case: 0 or 1 node => return head
    if(head==NULL || head->next==NULL) return head;

    // At each step, we assume the recursion will reverse the list after the current node.
    // So, when we call reverseRec(head->next), we are saying:
    // “Please reverse everything after me, I’ll fix my pointer later.”
    Node* newHead = recursiveReverseLL(head->next);

    // current node ke aage ki LL reverse ho chuki hai, ab new head dene se phle uska link set krdo
    // 1 2 3 4 => suppose current node is 1, so, 2 3 4 already reverse ho chuke hai
    // now, 4 is the new head and 2 is the last node
    // so, head->next->next is 1->2->next (1 is current head) => 2 ko 1 se link kr rhe hai and fir 1 ke next ko NULL
    head->next->next = head;
    head->next = NULL;

    return newHead;
}

void LinkedList::recRev(Node* q, Node* p){
    if(p!=0){
        recRev(p, p->next);
        p->next = q;
    }else{
        head = q;
    }
}

void LinkedList::concat(Node* head1, Node* head2){
    Node* p = head1;
    while(p->next != NULL){
        p=p->next;
    }
    p->next = head2;
    head2 = NULL;
}

Node* LinkedList::merge2LL(Node* p, Node* q){
    // third => head of new merged LL
    // last => last node of new merged LL
    Node *third, *last;

    if(p==0 && q==0) return NULL;
    else if(p==0 && q!=0) return q;
    else if(p!=0 && q==0) return p;

    if(p->data < q->data){
        third = last = p;
        p=p->next;
        last->next = NULL;
    }else{
        third = last = q;
        q=q->next;
        last->next = NULL;
    }

    while(p && q){
        if(p->data < q->data){
            last->next = p;
            last = p;
            p=p->next;
            last->next = NULL;
        }else{
            last->next = q;
            last = q;
            q=q->next;
            last->next = NULL;
        }
    }

    if(p != NULL) last->next = p;
    else if(q != NULL) last->next = q;

    return third;
}

// Fast & slow pointer technique
// Floyd's Cycle finding algorithm
// Hare-Tortoise algorithm
bool LinkedList::isLoop(Node* head){
    // Check if head is NULL or head->next==NULL (means single node)
    if(head==NULL || head->next==NULL) return false;
    Node *p = head, *q = head;

    while(p && q){
        p=p->next;
        q=q->next;
        if(q) q=q->next;

        if(p==q) return true;
    }
    return false;
}

Node* LinkedList::startOfLoop(Node* head){
    // Check if head is NULL or head->next==NULL (means single node)
    if(head==NULL || head->next==NULL) return NULL;
    
    Node *p = head, *q = head;
    while(p && q){
        p=p->next;
        q=q->next;
        if(q) q=q->next;

        // p==q means we have reached the end point of cycle
        if(p==q){
            p = head;
            while(p != q){
                p=p->next;
                q=q->next;
            }
            return p;          // starting point of cycle
        }
    }
    return NULL;               // means no cylce is there
}

void LinkedList::removeLoop(Node* head){
    if(head==NULL || head->next==NULL) return;
    
    Node *p = head, *q = head;
    while(p && q){
        p=p->next;
        q=q->next;
        if(q) q=q->next;
        
        if(p==q){
            // it is not guarantee that p==q will be there only and only at last node
            // That's why we can't make q->next=NULL directly
            // eg testcase: 1 -> 2 -> 3 -> 4 -> 5 -> 3 (loop is from last node 3 to 5)
            // That's why we need to find the starting point of loop and ending point
            // so that we remove the loop from the correct node by making its next NULL
            p = head;
            while(p!=q){
                p=p->next;
                q=q->next;
            }
            while(q->next != p){
                q=q->next;
            }
            q->next = NULL;
            
            return;
        }
    }
}

// Middle node of LL by simply dividing the length
Node* LinkedList::middle(Node* head){
    Node* p = head;
    int c = count(head);
    c = c/2;

    for(int i=0; i<c; i++) p=p->next;
    return p;
}

// Middle node of LL by taking two pointers => fast & slow
// By the time q reaches the end of the LL => p will be at the middle node
// when q==NULL, stop moving p
Node* LinkedList::middle2(Node* head){
    Node* fast = head;
    Node* slow = head;

    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

// REFER to LEETCODE for INTERSECTION of two linked lists question: https://leetcode.com/problems/intersection-of-two-linked-lists/
// It has all approaches

// APPROACH 1: Using 2 stacks
Node* LinkedList::IntersectionOfTwoLL1(Node* head1, Node* head2){
    // traverse to the end of both the LL & push the nodes in 2 stacks
    // pop out the nodes from the stacks until you found a different node
    // as ulta aane pe nodes same hongi till intersection point
    
    Node* p = head1;
    Node* q = head2;
    Node* ans = NULL;
    
    stack<Node *> s1;
    stack<Node *> s2;

    while(p != NULL){
        s1.push(p);
        p = p->next;
    }

    while(q != NULL){
        s2.push(q);
        q = q->next;
    }

    while(!s1.empty() && !s2.empty()){
        if(s1.top() != s2.top()) break;
        
        ans = s1.top();
        s1.pop();
        s2.pop();
    }
    return ans;
}

// APPROACH 2: Using 2 pointers
Node* LinkedList::IntersectionOfTwoLL2(Node* headA, Node* headB){
    Node* p1 = headA;
    Node* p2 = headB;

    if(p1==NULL || p2==NULL) return NULL;

    while(p1 && p2 && p1!=p2){
        p1 = p1->next;
        p2 = p2->next;

        if(p1==p2) return p1;

        if(p1==NULL) p1 = headB;
        if(p2==NULL) p2 = headA;
    }

    return p1;       // NULL
}

// LEETCODE QUE: Remove LL elements
// eg: [1,2,6,3,4,5,6] val=6 (remove all 6)
// eg: [7,7,7,7,7] val=7 (remove all 7)

Node* LinkedList::removeLLElements1(Node* head, int val){
    // Remove all leading nodes with value == val
    // example: 6 6 6 1 2 3 => remove 6
    // toh phle leadin wale sab hta do => 1 2 3
    while(head && head->data == val) head=head->next;

    // now either head is null or a node with val != target
    Node *p = head;
    while(p && p->next){
        if(p->next->val == val) p->next = p->next->next;
        else p=p->next;
    }
    return head;
}

int main(){
    
    int arr[] = {1,2,3,4,5};

    LinkedList ll(arr, 5);

    cout<<"Linked List: ";
    ll.display(ll.head);
    cout<<endl;

    cout<<"Length of LL: "<<ll.count(ll.head)<<endl;
    cout<<"Sum: "<<ll.sum(ll.head)<<endl;
    cout<<"Maximum Element: "<<ll.maxEle(ll.head)<<endl;
    cout<<"Linear Search: "<<ll.linearSearch(ll.head, 4)<<endl;

    // ll.Insert(ll.head, 3, 100);
    // ll.display(ll.head);

    // '&head' is the address of the head pointer, which is a pointer to a pointer of type Node.
    // By passing &head as the first argument to deleteNode(), we are passing a double pointer to the head of the linked list.
    // The function can then update the head pointer by dereferencing headRef (i.e., *headRef).
    cout<<ll.deleteNode(&ll.head, 0)<<endl;
    ll.display(ll.head);

    cout<<"Check Sorted: "<<ll.checkSort(ll.head)<<endl;
    cout<<"Reversed LL: "<<ll.revLinksLL(ll.head);

    return 0;
}
