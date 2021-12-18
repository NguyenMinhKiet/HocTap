#include <iostream>
#include <math.h>
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
    return (k.head == NULL);
}

//Create List
void InitLinkedList(linkedlist &k)
{
    k.head = k.tail = NULL;
}

// insert x to  tail of list
int InsertAfter(linkedlist &k, int x)
{
    Node p = new tagNode;
    if (p == NULL)
        return 0;
    p->data = x;
    p->next = NULL;
    if (isEmpty(k))
    {
        k.head = k.tail = p;
    }
    else
    {
        k.tail->next = p;
        k.tail = p;
    }
    return 2;
}

// insert data to list
void InsertDataToList(linkedlist &k, int n)
{
    int x;
    int i = 0;
    while (i < n)
    {
        cout << "Data slot [" << i << "] = ";
        cin >> x;
        InsertAfter(k, x);
        i++;
    }
}

// print data of list to screen
void PrintDataToScreen(linkedlist &k)
{
    if (isEmpty(k))
    {
        cout << "Empty list pls insert data\n";
        exit(1);
    }
    for (Node q = k.head; q != NULL; q = q->next)
    {
        cout << q->data << " ";
    }
    cout << "\n";
}

int countNode(linkedlist k)
{
    Node p = k.head;
    if (!p)
        return 0;
    int count = 0;
    while (p)
    {
        count++;
        p = p->next;
    }
    return count;
}

int sumlist(linkedlist k)
{
    Node p = k.head;
    int sum = 0;
    if (!p)
        return 0;
    while (p)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int closestNode(linkedlist k)
{
    Node p = k.head;
    if (!p)
        return 0;
    float avg = sumlist(k) * 1.0 / countNode(k);
    float closest = abs(p->data - avg);
    int q = p->data;
    while (p)
    {
        if (abs(p->data - avg) < closest)
        {
            closest = abs(p->data - avg);
            q = p->data;
        }
        p = p->next;
    }
    return q;
}

int main()
{
    linkedlist k;
    InitLinkedList(k);
    InsertDataToList(k, 5);
    PrintDataToScreen(k);
    cout << "Sum list = " << sumlist(k) << "\n";
    cout << "Count Node = " << countNode(k) << "\n";
    cout << "avg value = " << sumlist(k) * 1.0 / countNode(k) << "\n";
    cout << "closest value is " << closestNode(k);
    return 0;
}
