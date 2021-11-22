int findMax(LinkedList k){
    Node temp = k.Head;
    Node p = temp->Next;
    while(p){
        if(p->Data > temp->Data)
            temp = p;
        p = p->Next;
    }
    return temp->Data;
}