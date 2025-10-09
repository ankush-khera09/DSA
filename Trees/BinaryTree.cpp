#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// USING STL QUEUE & STACK

class Node{
    public:
        Node* lchild;
        int data;
        Node* rchild;

        Node(int x){
            this->data = x;
            this->lchild = NULL;
            this->rchild = NULL;
        }
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

        void MorrisTraversal(Node* p);        // InOrder without Recursion & Stack

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
    int x;
    queue<Node*> q;

    cout<<"Enter Root Value: ";
    cin>>x;

    this->root = new Node(x);
    q.push(root);

    while(!q.empty()){
        // queue se ek node pointer bhar nikala
        Node *p = q.front();
        q.pop();

        // usse pucha if uska left child hai
        cout<<"Enter left child of "<<p->data<<" : ";
        cin>>x;

        // if left child exists
        if(x != -1){
            Node *temp = new Node(x);
            p->lchild = temp;      // p ke lchild ko isse point kra diya
            q.emplace(temp);       // lchild ke address ko queue me daal diya
        }

        // Asking if right child exists
        cout<<"Enter right child of "<<p->data<<" : ";
        cin>>x;

        // if right child exists
        if(x != -1){
            Node *temp = new Node(x);
            p->rchild = temp;      // p ke lchild ko isse point kra diya
            q.emplace(temp);       // lchild ke address ko queue me daal diya
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

// InOrder Traversal without Recursion or Stack
void Tree::MorrisTraversal(Node* root){
    
    if(root == NULL) return;

    Node* curr = root;
    
    while(curr!=NULL){
        if(curr->lchild == NULL){
            cout<<curr->data<<" ";
            curr = curr->rchild;
        }else{
            // Find InOrder Predecessor of current node
            Node* pred = curr->lchild;
            while(pred->rchild != NULL && pred->rchild != curr){
                pred = pred->rchild;
            }
            // making temporary link
            if(pred->rchild == NULL){
                pred->rchild = curr;
                curr = curr->lchild;
            }else{
                // removing temporary link
                pred->rchild = NULL;
                cout<<curr->data<<" ";
                curr = curr->rchild;
            }
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

void Tree::IterPostOrder(Node *root){
    stack<Node*> s;
    while(root || !s.empty()){
        if(root){
            s.push(root);    // push 2 times
            s.push(root);
            root = root->lchild;
        }else{
            root = s.top();
            s.pop();

            // if current root (first ele nikal liya stack se) == current top of stack (duplicate ele in stack)
            // this means, first time visit kiya hai => so, move to right child
            // if not then this means us node pe 2nd time aaye hai => right child already covered => now print it
            if(!s.empty() && root==s.top()){
                root = root->rchild;
            }else{
                cout<<root->data<<" ";
                root = NULL;
            }
        }
    }
}

void Tree::LevelOrder(Node *p){
    // queue<Node*> q;

    // cout<<p->data<<" ";         // printing root node's data
    // q.emplace(p);               // pushing root node in queue

    // while(!q.empty()){
    //     p = q.front();
    //     q.pop();
    //     // if left child exists
    //     if(p->lchild){
    //         cout<<p->lchild->data<<" ";
    //         q.emplace(p->lchild);
    //     }
    //     // if right child exists
    //     if(p->rchild){
    //         cout<<p->rchild->data<<" ";
    //         q.emplace(p->rchild);
    //     }
    // }


    queue<Node*> q;

    q.push(p);

    while(!q.empty()){
        Node* front = q.front();
        q.pop();

        cout<<front->data<<" ";

        if(front->lchild) q.push(front->lchild);
        if(front->rchild) q.push(front->rchild);
    }
}

// PRINTING LEVELS IN DIFFERENT LINES: https://leetcode.com/problems/binary-tree-level-order-traversal/description/

/*

// with & without NULL: see leetcode
// with NULL:
void Tree::LevelOrder(Node *p){
    queue<Node*> q;

    q.push(p);
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

// no. of nodes
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

int Tree::Height(Node *root){
    if(root==NULL) return 0;

    int left = Height(root->left);
    int right = Height(root->right);
    return max(left, right)+1;
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

    cout<<"Morris Traversal: ";
    t.MorrisTraversal(t.root);
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


/*

BINARY TREE PRACTICE QUESTIONS: LOVE BABBAR:

1. Diameter of a Binary Tree: https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1
2. Check for Balanced Tree: https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1
3. Determine if Two Trees are Identical: https://practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1
4. Sum Tree: https://practice.geeksforgeeks.org/problems/sum-tree/1

5. ZigZag Tree Traversal: https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1
6. Boundary Traversal of Binary Tree: https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
7. Vertical Traversal of Binary Tree: https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1
8. Top View of Binary Tree: https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1
9. Bottom View of Binary Tree: https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
10. Left View of Binary Tree: https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1
11. Right View of Binary Tree: https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1
12. Diagonal Traversal of Binary Tree: https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1

13. Sum of the Longest Bloodline of a Tree (Sum of nodes on the longest path from root to leaf node): https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1
14. Lowest Common Ancestor in a Binary Tree: https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1
15. K Sum Paths: https://practice.geeksforgeeks.org/problems/k-sum-paths/1
16. Kth Ancestor in a Tree: https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1
17. Maximum sum of Non-adjacent nodes: https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1

18. Construct Tree from Inorder & Preorder: https://practice.geeksforgeeks.org/problems/construct-tree-1/1
19. 

    DO MAXIMUM PATH SUM QUE ON LEETCODE

*/
