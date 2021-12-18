#include <iostream>

typedef struct tagNode
{
    int Data;
    tagNode *Next;
    tagNode *Prev;
}*Node;

typedef struct taglist
{
    Node Head; // phần tử đầu
    Node Tail; // phần tử cuối
} LinkedList;

//Kiểm tra DSLK rỗng?
int isEmpty(LinkedList k)
{
    return (k.Head == NULL);
}

//Khởi tạo DSLK rỗng
void initLinkedList(LinkedList &k)
{
    k.Head = k.Tail = NULL;
}

/*
Thêm ở đầu
p->Next = l.Head;
l.Head->Prev = p;
l.Head = p;
 Thêm ở cuối
l.Tail->Next = p;
p->Prev = l.Tail;
l.Tail = p;
*/

int insertNodeAtHead(LinkedList &l, int x)
{
    Node p = new tagNode;
    if (p == NULL)
        return 0;
    p->Data = x;
    p->Prev = NULL;
    p->Next = NULL;
    if (isEmpty(l))
    {
        l.Head = l.Tail = p;
    }
    else
    {
        p->Next = l.Head;
        l.Head->Prev = p;
        l.Head = p; 
    }
    return 1;
}

//Thêm 1 phần tử x vào cuối DSLK k
int insertNodeAtTail(LinkedList &l, Node x)
{
    Node p = new tagNode;
    if (p == NULL)
        return 0;
    p->Data = x->Data;
    p->Prev = NULL;
    p->Next = NULL;
    if (isEmpty(l))
    {
        l.Head = l.Tail = p;
    }
    else
    {
        l.Tail->Next = p;
        p->Prev = l.Tail;
        l.Tail = p;
    }
    return 2;
}