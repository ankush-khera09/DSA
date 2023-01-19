#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// USING STL QUEUE & STACK

class Node{
    public:
        Node* lchild;
        int data;
        Node* rchild;
};

class Tree{
    public:
        Node* root;

        Tree(){
            root = NULL;
        }

        void CreateTree();

        void PreOrder(Node* p);             // Recursive PreOrder Traversal
        void IterPreOrder(Node *p);         // Iterative PreOrder Traversal

        // if "root" is made private => we can't call this fn with root as parameter in main()
        // So, we need to make a dummy fn for this like:
        // void PreOrder(){ PreOrder(root); }
        // In main() => call as PreOrder() => this non-parameterised fn will call parameterised fn by passing root 

        void InOrder(Node *p);
        void IterInOrder(Node *p);

        void PostOrder(Node *p);
        void IterPostOrder(Node *p);

        void LevelOrder(Node *p);

        int Count(Node *p);               // counting no. of nodes
        int Height(Node *p);              // Height of the tree
        int Sum(Node *p);                 // Sum of all elements in the tree
        int deg2NodeCount(Node *p);       // Counting no. of nodes with degree 2
        int deg1NodeCount(Node *p);
        int LeafNodeCount(Node *p);
        int NonLeafNodeCount(Node *p);

        // See codes of Generate Binary Tree from 'InOrder & PreOrder' & 'InOrder & PostOrder' on GFG Practice
};

void Tree::CreateTree(){
    Node *p, *t;        // temporary pointers
    int x;
    queue<Node*> q;     // Making STL queue

    cout<<"Enter Root Value: ";
    cin>>x;

    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.emplace(root);

    while(!q.empty()){
        // queue se ek node pointer bhar nikala
        p = q.front();
        q.pop();

        // usse pucha if uska left child hai
        cout<<"Enter left child of "<<p->data<<" : ";
        cin>>x;

        // if left child exists
        if(x != -1){
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;      // p ke lchild ko isse point kra diya
            q.emplace(t);       // lchild ke address ko queue me daal diya
        }

        // Asking if right child exists
        cout<<"Enter right child of "<<p->data<<" : ";
        cin>>x;

        // if right child exists
        if(x != -1){
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;      // p ke lchild ko isse point kra diya
            q.emplace(t);       // lchild ke address ko queue me daal diya
        }
    } 
}

void Tree::PreOrder(Node *p){
    if(p){
        cout<<p->data<<" ";
        PreOrder(p->lchild);
        PreOrder(p->rchild);
    }
}

void Tree::IterPreOrder(Node *p){
    stack<Node*> s;
    while(p!=NULL || !s.empty()){
        if(p){
            cout<<p->data<<" ";       // print data
            s.emplace(p);               // push address of node in stack
            p = p->lchild;              // move to lchild
        }else{
            // p==NULL means no more left child in the sequence
            p = s.top();                // pop out the previous parent node   
            s.pop();
            p = p->rchild;              // move to its right child
        }
    }
}

void Tree::InOrder(Node *p){
    if(p){
        InOrder(p->lchild);
        cout<<p->data<<" ";
        InOrder(p->rchild);
    }
}

void Tree::IterInOrder(Node *p){
    stack<Node*> s;
    while(p || !s.empty()){
        if(p){
            s.emplace(p);
            p = p->lchild;
        }else{
            p = s.top();
            s.pop();
            cout<<p->data<<" ";
            p = p->rchild;
        }
    }
}

void Tree::PostOrder(Node *p){
    if(p){
        PostOrder(p->lchild);
        PostOrder(p->rchild);
        cout<<p->data<<" ";
    }
}

void Tree::IterPostOrder(Node *p){
    stack<long int> s;
    long int temp;
    while(p || !s.empty()){
        if(p){
            s.push((long int)p);        // if p!=0 => push in stack => move to lchild
            p = p->lchild;
        }else{
            temp = s.top();            // if p==0 => pop out => check if +ve or -ve
            s.pop();
            if(temp>0){                  // if +ve => push(-ve) in stack => move to rchild
                s.emplace(-temp);
                p = ((Node*)temp)->rchild;
            }else{                                // if -ve => print & make it NULL again so that it can pop again
                cout<<((Node*)(-1 * temp))->data<<" ";
                p = NULL;
            }
        }
    }
}

void Tree::LevelOrder(Node *p){
    queue<Node*> q;

    cout<<p->data<<" ";         // printing root node's data
    q.emplace(p);               // pushing root node in queue

    while(!q.empty()){
        p = q.front();
        q.pop();
        // if left child exists
        if(p->lchild){
            cout<<p->lchild->data<<" ";
            q.emplace(p->lchild);
        }
        // if right child exists
        if(p->rchild){
            cout<<p->rchild->data<<" ";
            q.emplace(p->rchild);
        }
    }
}

// PRINTING LEVELS IN DIFFERENT LINES:

/*
void Tree::LevelOrder(Node *p){
    queue<Node*> q;

    q.emplace(p);
    q.push(NULL);

    while(!q.empty()){
        Node *temp = q.front();
        q.pop();

        if(temp==NULL){
            cout<<endl;          // means ek level complete hogya hai => move to next line
            if(!q.empty()){
                q.push(NULL);       // queue has still some child nodes in it => push 'NULL' for next level
            }
        }else{
            cout<<temp->data<<" ";
            if(temp->lchild){
                q.emplace(temp->lchild);
            }
            if(temp->rchild){
                q.emplace(temp->rchild);
            }
        }
    }
}
*/

int Tree::Count(Node *p){
    int x, y;
    if(p){
        x = Count(p->lchild);
        y = Count(p->rchild);
        return x+y+1;
    }
    return 0;
}

// or
/*
int Tree::Count(Node *p){
    if(p==NULL) return 0;
    return Count(p->lchild)+Count(p->rchild)+1;
}
*/

int Tree::Height(Node *p){
    int x=0, y=0;
    if(p){
        x = Height(p->lchild);
        y = Height(p->rchild);
        if(x>y) return x+1;
        else return y+1;
    }
    return 0;
}

int Tree::Sum(Node *p){
    int x, y;
    if(p){
        x = Sum(p->lchild);
        y = Sum(p->rchild);
        return x+y+p->data;
    }
    return 0;
}

int Tree::deg2NodeCount(Node *p){
    int x, y;
    if(p){
        x = deg2NodeCount(p->lchild);
        y = deg2NodeCount(p->rchild);
        if(p->lchild && p->rchild) return x+y+1;
        else return x+y;
    }
    return 0;
}

int Tree::deg1NodeCount(Node *p){
    int x, y;
    if(p){
        x = deg2NodeCount(p->lchild);
        y = deg2NodeCount(p->rchild);
        if(p->lchild!=NULL xor p->rchild!=NULL) return x+y+1;
        else return x+y;
    }
    return 0;
}

int Tree::LeafNodeCount(Node *p){
    int x, y;
    if(p){
        x = LeafNodeCount(p->lchild);
        y = LeafNodeCount(p->rchild);
        if(p->lchild==NULL && p->rchild==NULL) return x+y+1;
        else return x+y;
    }
    return 0;
}

int Tree::NonLeafNodeCount(Node *p){
    int x, y;
    if(p){
        x = NonLeafNodeCount(p->lchild);
        y = NonLeafNodeCount(p->rchild);
        if(p->lchild || p->rchild) return x+y+1;
        else return x+y;
    }
    return 0;
}

int main(){
    
    Tree t;
    t.CreateTree();

    cout<<"PreOrder Traversal:"<<endl;
    t.PreOrder(t.root);
    cout<<endl;
    t.IterPreOrder(t.root);
    cout<<endl;

    cout<<"InOrder Traversal:"<<endl;
    t.InOrder(t.root);
    cout<<endl;
    t.IterInOrder(t.root);
    cout<<endl;

    cout<<"PostOrder Traversal:"<<endl;
    t.PostOrder(t.root);
    cout<<endl;
    t.IterPostOrder(t.root);
    cout<<endl;

    cout<<"LevelOrder Traversal"<<endl;
    t.LevelOrder(t.root);
    cout<<endl;

    cout<<"Count: "<<t.Count(t.root)<<endl;
    cout<<"Height: "<<t.Height(t.root)<<endl;
    cout<<"Sum: "<<t.Sum(t.root)<<endl;
    cout<<"deg2NodeCount: "<<t.deg2NodeCount(t.root)<<endl;
    cout<<"deg1NodeCount: "<<t.deg1NodeCount(t.root)<<endl;
    cout<<"LeafNodeCount: "<<t.LeafNodeCount(t.root)<<endl;
    cout<<"NonLeafNodeCount: "<<t.NonLeafNodeCount(t.root)<<endl;

    return 0;
}