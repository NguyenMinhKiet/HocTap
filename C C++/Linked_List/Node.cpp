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

//Thêm phần tử x vào đầu DSLK k
int insertNodeAtHead(LinkedList &k, int x)
{
    Node p = new tagNode;
    if (p == NULL)
        return 0;
    p->Data = x;
    p->Next = NULL;
    if (isEmpty(k))
    {
        k.Head = k.Tail = p;
    }
    else
    {
        p->Next = k.Head;
        k.Head = p;
    }
    return 1;
}

//Thêm 1 phần tử x vào cuối DSLK k
int insertNodeAtTail(LinkedList &k, Node x)
{
    Node p = new tagNode;
    if (p == NULL)
        return 0;
    p->Data = x->Data;
    p->Next = NULL;
    if (isEmpty(k))
    {
        k.Head = k.Tail = p;
    }
    else
    {
        k.Tail->Next = p;
        k.Tail = p;
    }
    return 2;
}
//Thêm 1 phần tử x vào sau  Node q
int insertNodeAtAfter(LinkedList &k, Node q, int x)
{
    Node p = new tagNode;
    if (p == NULL)
        return 0;
    p->Data = x;
    p->Next = NULL;
    if (isEmpty(k))
    {
        k.Head = k.Tail = p;
    }
    else
    {
        p->Next = q->Next;
        q->Next = p;
        if (q == k.Tail)
            k.Tail = p;
    }
    return 3;
}
//Thêm 1 phần tử x vào trước  Node q
int insertNodeBefore(LinkedList &k, Node q, int value)
{
    //nếu node q là pt đầu tiên dùng insertNodeHead
    if (q == k.Head)
        return insertNodeAtHead(k, value);
    Node p = new tagNode;
    if (!p)
        return 0;
    p = k.Head;
    while (p->Next != q)
        p = p->Next;
    value = p->Data;
    insertNodeAtAfter(k, p, value);
    return 4;
}
//  Nối DSLK này vào cuối DSLK kia
void appendList(LinkedList &l, LinkedList &l1)
{
    if (isEmpty(l))
        l = l1;
    else
    {

        l.Tail->Next = l1.Head;
        if (!isEmpty(l1))
            l.Tail = l1.Tail;
    }
}
//Hủy 01 phần tử ở đầu DSLK
int removeNodeAtHead(LinkedList &l)
{
    Node p = l.Head;
    if (isEmpty(l))
        return -1;
    l.Head = p->Next;
    if (l.Head == NULL)
        l.Tail = NULL;
    p->Next = NULL;
    delete p;
    return 1;
}

//Hủy 01 phần tử ở cuối DSLK
int removeNodeAtTail(LinkedList &l)
{
    Node p = l.Head; // tạo 1 Node p = giá trị đầu của DSLK l
    Node q = NULL;   // tạo 1 Node q không có giá trị
    while (p != l.Tail)
    { // chạy đến giá trị gần cuối
        q = p;
        p = p->Next;
    }
    if (!p)
        return -1; // nếu p không có giá trị -> trả vể -1
    if (q)
    {
        q->Next = NULL;
        l.Tail = q;
    }
    else
    {
        l.Head = l.Tail = NULL;
    }
    delete p;
    return 1;
}

//Hủy 01 phần tử có giá trị X trong DSLK
int removeNode(LinkedList &l, int X)
{
    Node p = l.Head;
    if (!p)
        return -1;
    if (p->Data != X && l.Tail->Data != X)
    {

        Node q = NULL;
        while (p->Data != X && p)
        {
            q = p;
            p = p->Next;
        }
        if (!p)
            return 0;
        q->Next = p->Next;
        p->Next = NULL;
        delete p;
    }
    else
    {
        if (p->Data = X)
            return removeNodeAtHead(l);
        if (l.Tail->Data = X)
            return removeNodeAtTail(l);
    }
    return 1;
}

//Tìm 01 phần tử trong DSLK
Node searchNode(LinkedList l, int x)
{
    Node p = l.Head;
    if (p == NULL)
        return NULL;
    while (p)
    {

        if (p->Data == x)
            return p;
        p = p->Next;
    }
    return NULL;
}

void divideList(LinkedList &l, LinkedList &l1, LinkedList &l2)
{
    Node p;
    while (!isEmpty(l))
    {
        p = l.Head;
        l.Head = p->Next;
        p->Next = NULL;
        insertNodeAtTail(l1, p);
        if (!isEmpty(l))
        {
            p = l.Head;
            l.Head = p->Next;
            p->Next = NULL;
            insertNodeAtTail(l2, p);
        }
    }
    initLinkedList(l);
}
//Sắp xếp DSLK theo PP MergeSort (tt)
void mergeList(LinkedList &l, LinkedList &l1, LinkedList &l2)
{
    Node p;
    while (!isEmpty(l1) && !isEmpty(l2))
    {
        if (l1.Head->Data >= l2.Head->Data)
        {

            p = l1.Head;
            l1.Head = p->Next;
            p->Next = NULL;
        }
        else
        {

            p = l2.Head;
            l2.Head = p->Next;
            p->Next = NULL;
        }

        insertNodeAtTail(l, p);
    }
    if (!isEmpty(l1))
        appendList(l, l1);
    if (!isEmpty(l2))
        appendList(l, l2);
    initLinkedList(l1);
    initLinkedList(l2);
}

// Sắp xếp DSLK theo PP MergeSort
void mergeSort(LinkedList &l)
{
    LinkedList l1, l2;
    if (l.Head == l.Tail)
        return;
    initLinkedList(l1);
    initLinkedList(l2);
    divideList(l, l1, l2);
    mergeSort(l1);
    mergeSort(l2);
    mergeList(l, l1, l2);
}

void splitList(LinkedList &l, LinkedList &l1, LinkedList &l2, Node &x)
{
    Node p;
    x = l.Head;
    l.Head = x->Next;
    x->Next = NULL;
    while (!isEmpty(l))
    {
        p = l.Head;
        l.Head = p->Next;
        p->Next = NULL;
        if (p->Data >= x->Data)
            insertNodeAtTail(l1, p);
        else
            insertNodeAtTail(l2, p);
    }
    initLinkedList(l);
}

void concatList(LinkedList &l, LinkedList &l1, Node &x, LinkedList &l2)
{
    appendList(l, l1);
    insertNodeAtTail(l, x);
    appendList(l, l2);
    initLinkedList(l1);
    initLinkedList(l2);
}
// Sắp xếp DSLK theo PP QuickSort
void quickSort(LinkedList &l)
{
    LinkedList l1, l2;
    Node X;
    if (l.Head == l.Tail)
        return;
    initLinkedList(l1);
    initLinkedList(l2);
    splitList(l, l1, l2, X);
    quickSort(l1);
    quickSort(l2);
    concatList(l, l1, X, l2);
    initLinkedList(l1);
    initLinkedList(l2);
}

//lấy pt đầu của chuỗi
Node getHead(LinkedList &k)
{
    Node p = k.Head;
    k.Head = p->Next;
    p->Next = NULL;
    return p;
}

int findMax(LinkedList k)
{
    Node temp = k.Head;
    Node p = temp->Next;
    while (p)
    {
        if (p->Data > temp->Data)
            temp = p;
        p = p->Next;
    }
    return temp->Data;
}

int countDigit(int n)
{
    int count = 0;
    while (n)
    {
        n /= 10;
        count++;
    }
    return count;
}

int getDigit(int n, int t)
{
    long temp = 1;
    for (int i = 0; i < n; i++)
        temp *= 10;
    (t = t / 10);
    return (t / temp) % 10;
    (t % 10);
}

int getMaxDigit(LinkedList l)
{
    int max = findMax(l);
    return countDigit(max);
}

void send2Box(int n, LinkedList &l, LinkedList temp[])
{
    Node p;
    while (!isEmpty(l))
    {
        p = getHead(l);
        insertNodeAtTail(temp[getDigit(n, p->Data)], p);
    }
    initLinkedList(l);
}

// Sắp xếp DSLK theo PP RadixSort
void radixSort(LinkedList &l)
{
    int i;
    LinkedList temp[10];
    if (l.Head == l.Tail)
        return;
    for (int i = 0; i < 10; i++)
        initLinkedList(temp[i]);
    int numDigit = getMaxDigit(l);
    for (i = 0; i < numDigit; i++)
    {
        send2Box(i, l, temp);
        for (int j = 0; j < 10; j++)
        {

            if (!isEmpty(temp[j]))
                appendList(l, temp[j]);
            initLinkedList(temp[j]);
        }
    }
}