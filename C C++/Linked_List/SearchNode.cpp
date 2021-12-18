#include <iostream>
//khai báo
typedef struct tagNode{
    int Data;
    struct tagNode *Next;
}*Node; 

typedef struct taglist{
    Node Head; // phần tử đầu
    Node Tail; // phần tử cuối
}LinkedList;

//Kiểm tra DSLK rỗng?
int isEmpty(LinkedList k){
   return (k.Head==NULL);
}

//Tìm 01 phần tử trong DSLK
Node searchNode(LinkedList l, int x){
    Node p = l.Head;
    if(p==NULL) return NULL;
    while (p){
        if(p->Data = x) return p;
        p = p->Next;    
    }
    return NULL;
}