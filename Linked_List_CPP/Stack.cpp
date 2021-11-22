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
typedef LinkedList Stack;
//Kiểm tra DSLK rỗng?
int isEmpty(Stack k)
{
    return (k.Head == NULL);
}

//Khởi tạo DSLK rỗng
void initLinkedList(Stack &k)
{
    k.Head = k.Tail = NULL;
}

int isEmpty(Stack st)
{
    return st.Head == NULL;
}

int size(Stack st)
{
    Node p = st.Head;
    int count = 0;
    while (p)
    {
        count++;
        p = p->Next;
    }
    return count;
}
//Thêm vào đầu Stack
int push(Stack &st, int x)
{
    Node p = new tagNode;
    if (p == NULL)
        return 0;
    p->Data = x;
    p->Next = NULL;
    if (isEmpty(st))
    {
        st.Head = st.Tail = p;
    }
    else
    {
        p->Next = st.Head;
        st.Head = p;
    }
    return 1;
}
//lấy đối tượng ở  đầu Stack
int pop(Stack &st)
{
    Node p = st.Head;
    if (isEmpty(st))
        return -1;
    st.Head = p->Next;
    if (st.Head == NULL)
        st.Tail = NULL;
    p->Next = NULL;
    int x = p->Data;
    delete p;
    return x;
}

//lấy giá trị ở đầu stack
int top(Stack st)
{
    return st.Head->Data;
}