void InsertLast(Node* &first, int x){
    Node* temp = new Node;
    temp->data = x;
    temp->next = NULL;

    if(first==NULL) first = temp;
    else{
        Node *last = first;
        while(last->next!=0) last=last->next;
        last->next = temp;
        last = temp;
    }
}