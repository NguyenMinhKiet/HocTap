#include <iostream>
#include <string>
#include <cctype>

using namespace std;
typedef struct tagNode
{
    int data;
    struct tagNode *next;
} * Node;
typedef struct taglist
{
    Node head;
    Node tail;
} linkedlist;
//Check List
int isEmpty(linkedlist k)
{
    if (k.head == NULL)
    {
        return 1;
    }
    return 0;
}
//Create List
void InitLinkedList(linkedlist &k)
{
    k.head = k.tail = NULL;
}
//Insert at last
void InsertAfter(linkedlist &k,int x)
{
    Node q = new tagNode;
    if (!q)
    {
        cout << "not enough memory";
    }
    
    q->data = x;
    q->next = NULL;
    if (isEmpty(k))
    {
        k.head = k.tail = q;
    }
    else
    {
        k.tail->next = q;
        k.tail = q;
    }
}

void InsertDataToList(linkedlist &k)
{   
    int x;
    int i = 0;
    do{
        cout<<"Data slot ["<<i<<"] = "; 
        cin>>x;
        if (x == 0) break;
        InsertAfter(k, x);
        i++;
    }
    while(true);
}

void PrintDataToScreen(linkedlist &k)
{
    for (Node q = k.head; q != NULL; q = q->next)
    {
        cout << q->data << " ";
    }
}

//  Nối DSLK này vào cuối DSLK kia
void appendList(linkedlist &l, linkedlist &l1)
{
    if (isEmpty(l))
        l = l1;
    else
    {

        l.tail->next = l1.head;
        if (!isEmpty(l1))
            l.tail = l1.tail;
    }
}



int main()
{
    linkedlist list;
    InitLinkedList(list);
    InsertDataToList(list);
    cout << "========Linked List========\n";
    PrintDataToScreen(list);
    return 0;
}