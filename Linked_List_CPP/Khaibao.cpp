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


int main(){
    
}