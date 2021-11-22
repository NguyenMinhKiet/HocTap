#include <iostream>
//khai báo
typedef struct tagNode
{
    int Data;
    struct tagNode *Next;
} * Node;

typedef struct taglist
{
    Node Head; // phần tử đầu
    Node Tail; // phần tử cuối
} Queue;
//Kiểm tra hàng chờ rỗng?
int isEmpty(Queue k)
{
    return (k.Head == NULL);
}
//chèn vào cuối của hàng chờ
int enqueue(Queue qu, int x)
{
    Node p = new tagNode;
    if (p == NULL)
        return 0;
    p->Data = x;
    p->Next = NULL;
    if (isEmpty(qu))
    {
        qu.Head = qu.Tail = p;
    }
    else
    {
        qu.Tail->Next = p;
        qu.Tail = p;
    }
    return 1;
}
//lấy Phần tử đầu của hàng chờ
int dequeue(Queue qu)
{
    return qu.Head->Data;
}