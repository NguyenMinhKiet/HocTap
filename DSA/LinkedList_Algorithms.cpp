#include <iostream>

using namespace std;

/* Linked List struct */
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
/* END Linked list struct */

/* Linked list Algorithms */

// Check List
int isEmpty(linkedlist k)
{
    if (k.head == NULL)
    {
        return true;
    }
    return false;
}

// Create List
void InitLinkedList(linkedlist &k)
{
    k.head = k.tail = NULL;
}

// Insert at last
void InsertAfter(linkedlist &k, int x)
{
    Node q = new tagNode;
    if (!q)
    {
        cout << "not enough memory";
        exit(1);
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

// Copy list k1 to list k2
linkedlist CopyList(linkedlist &k1, linkedlist &k2)
{
    Node p = k1.head;
    while (p != NULL)
    {
        InsertAfter(k2, p->data);
        p = p->next;
    }
    return k2;
}

// Insert Data to List
void InsertDataToList(linkedlist &k, int slot)
{
    int data, n;
    cout << "Quantity Element of Linked List " << slot << " : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Data slot [" << i + 1 << "] = ";
        cin >> data;
        InsertAfter(k, data);
    }
}

// Print Data to Screen
void PrintDataToScreen(linkedlist &k)
{
    Node p = k.head;
    if (isEmpty(k))
        cout << "Empty List";
    else
    {
        do
        {
            cout << p->data << "\t";
            p = p->next;
        } while (p != NULL);
    }
    cout << "\n";
}

//  append list l2 to list l1
void appendList(linkedlist &l1, linkedlist &l2)
{
    if (isEmpty(l1))
        l1 = l2;
    else
    {

        l1.tail->next = l2.head;
        if (!isEmpty(l2))
            l1.tail = l2.tail;
    }
}
/* END Linked List Algorithms */

/* Remove Althorithms */

// Remove data  at head
linkedlist removeNodeAtHead(linkedlist &l)
{
    Node p = l.head;
    if (isEmpty(l))
        return l;
    l.head = p->next;
    if (l.head == NULL)
        l.tail = NULL;
    p->next = NULL;
    delete p;
    return l;
}

// Remove same data
linkedlist removeSameValueinList(linkedlist &k1)
{
    linkedlist tmp;
    InitLinkedList(tmp);
    if (isEmpty(k1)) return k1;
    Node p = k1.head;
    Node q = new tagNode;
    while (p != NULL)
    {
        q = p->next;
        if (q != NULL)
        {
            if (p->data == q->data)
            {
                removeNodeAtHead(k1);
                p = k1.head;
            }
            else
            {
                InsertAfter(tmp, p->data);
                removeNodeAtHead(k1);
                p = k1.head;
            }
        }
        else
        {
            InsertAfter(tmp, p->data);
            p = p->next;
        }
    }
    InitLinkedList(k1);
    CopyList(tmp, k1);
    return k1;
}
/* END Remove Algorithms */

/*------ Sort Algorithms --------*/

// get value at location k of n
int digit(int n, int k)
{
    int value = 1;
    for (int i = 0; i < k; i++)
        value *= 10;
    return (n / value) % 10;
}

// Find max element of a Node in List
int countmaxNode(linkedlist &k)
{
    // Create tmp in order not to change data from Global list k1
    linkedlist tmp;
    InitLinkedList(tmp);
    CopyList(k, tmp);
    Node p = tmp.head;
    int n, tmpmax;
    int max = 0;
    while (p != NULL)
    {
        tmpmax = 0;
        while (p->data > 0)
        {
            tmpmax++;
            p->data /= 10;
        }
        if (tmpmax > max)
        {
            max = tmpmax;
        }
        p = p->next;
    }
    InitLinkedList(tmp);
    return max;
}

// Radix Sort Algorithms ( requite : same num of element ex: 1 1, 10 10, .. )
linkedlist RadixSort(linkedlist &k)
{
    linkedlist zero, one, two, three, four, five, six, seven, eight, nine;
    InitLinkedList(zero);
    InitLinkedList(one);
    InitLinkedList(two);
    InitLinkedList(three);
    InitLinkedList(four);
    InitLinkedList(five);
    InitLinkedList(six);
    InitLinkedList(seven);
    InitLinkedList(eight);
    InitLinkedList(nine);

    Node p = new tagNode;
    int number, max_Node;
    max_Node = countmaxNode(k);
    
    for (int i = 0; i < max_Node; i++)
    {
        p = k.head;
        while (p != NULL)
        {
            number = digit(p->data, i);
            if (number == 0)
            {
                InsertAfter(zero, p->data);
            }
            else if (number == 1)
            {
                InsertAfter(one, p->data);
            }
            else if (number == 2)
            {
                InsertAfter(two, p->data);
            }
            else if (number == 3)
            {
                InsertAfter(three, p->data);
            }
            else if (number == 4)
            {
                InsertAfter(four, p->data);
            }
            else if (number == 5)
            {
                InsertAfter(five, p->data);
            }
            else if (number == 6)
            {
                InsertAfter(six, p->data);
            }
            else if (number == 7)
            {
                InsertAfter(seven, p->data);
            }
            else if (number == 8)
            {
                InsertAfter(eight, p->data);
            }
            else if (number == 9)
            {
                InsertAfter(nine, p->data);
            }
            else
            {
                cout << "is not a number";
                return k;
            }
            p = p->next;
        }
        // append all list from 0 to 9
        appendList(eight, nine);
        appendList(seven, eight);
        appendList(six, seven);
        appendList(five, six);
        appendList(four, five);
        appendList(three, four);
        appendList(two, three);
        appendList(one, two);
        appendList(zero, one);

        // update list k
        InitLinkedList(k);
        CopyList(zero, k);

        // Delete all list from 0 to 9
        InitLinkedList(zero);
        InitLinkedList(one);
        InitLinkedList(two);
        InitLinkedList(three);
        InitLinkedList(four);
        InitLinkedList(five);
        InitLinkedList(six);
        InitLinkedList(seven);
        InitLinkedList(eight);
        InitLinkedList(nine);
    }
    return k;
}

// Insertion Sort
linkedlist Sortlist(linkedlist &l1)
{
    if (isEmpty(l1))
    {
        cout << "Empty list\n";
        return l1;
    }
    Node p = l1.head;
    Node q;
    int tmp;
    while (p != NULL)
    {
        q = p->next;
        while (q != NULL)
        {
            if (p->data > q->data)
            {
                tmp = p->data;
                p->data = q->data;
                q->data = tmp;
            }
            q = q->next;
        }
        p = p->next;
    }
    return l1;
}
/* END Sort Algorithms*/

/* Calculation Althorithms */

// Intersection Algorithms
linkedlist intersection(linkedlist &k1, linkedlist &k2, linkedlist &k3)
{
    // Create 2 linked list in order not to change data of  Global list k1, k2
    linkedlist tmp1, tmp2;
    InitLinkedList(tmp1);
    InitLinkedList(tmp2);
    CopyList(k1, tmp1);
    CopyList(k2, tmp2);

    if (isEmpty(tmp1))
    {
        InitLinkedList(tmp2);
        return k3;
    }
    if (isEmpty(tmp2))
    {
        InitLinkedList(tmp1);
        return k3;
    }

    RadixSort(tmp1);
    RadixSort(tmp2);
    Node p = tmp1.head;
    Node q = tmp2.head;

    while (p != NULL)
    {
        while (q != NULL)
        {
            if (p->data == q->data)
                InsertAfter(k3, p->data);
            q = q->next;
        }
        q = tmp2.head;
        p = p->next;
    }
    InitLinkedList(tmp1);
    InitLinkedList(tmp2);
    removeSameValueinList(k3);
    return k3;
}

// Subtraction Algorithms
linkedlist SubtractionList(linkedlist &k1, linkedlist &k2, linkedlist &k3)
{
    // Create 2 linked list to get data from k1, k2 in order to not change data of  Global list k1, k2
    linkedlist tmp1, tmp2;
    InitLinkedList(tmp1);
    InitLinkedList(tmp2);
    CopyList(k1, tmp1);
    CopyList(k2, tmp2);

    if (isEmpty(tmp1))
    {
        InitLinkedList(tmp2);
        return k3;
    }
    if (isEmpty(tmp2))
    {
        appendList(k3, tmp1);
        InitLinkedList(tmp1);
        return k3;
    }

    RadixSort(tmp1);
    cout<<"List 1 : ";
    PrintDataToScreen(tmp1);
    RadixSort(tmp2);
    cout<<"List 2 : ";
    PrintDataToScreen(tmp2);

    Node p = tmp1.head;
    Node q = tmp2.head;

    while (p != NULL)
    {
        if (q != NULL)
        {
            if (p->data == q->data)
            {
                removeNodeAtHead(tmp1);
                p = tmp1.head;
                removeNodeAtHead(tmp2);
                q = tmp2.head;
            }
            else 
            {
                    InsertAfter(k3, p->data);
                    removeNodeAtHead(tmp1);
                    p = tmp1.head;
                    removeNodeAtHead(tmp2);
                    q = tmp2.head;
            }   
        }
        else
        {
            while (p != NULL)
            {
                InsertAfter(k3,p->data);
                p = p->next;
            }
        }
     }
        
    InitLinkedList(tmp1);
    InitLinkedList(tmp2);
    return k3;
}

/* END Calculation Algorithms */

int main()
{
    linkedlist list1, list2, result1, result2, result3;
    InitLinkedList(list1);
    InitLinkedList(list2);
    InitLinkedList(result1);
    InitLinkedList(result2);
    InitLinkedList(result3);
    InsertDataToList(list1, 1);
    InsertDataToList(list2, 2);
    cout << "List 1:\t";
    PrintDataToScreen(list1);
    cout << "List 2:\t";
    PrintDataToScreen(list2);
    intersection(list1, list2, result1);
    cout << "Intersection: DONE\n";
    SubtractionList(list1, list2, result3);
    cout << "Subtraction: DONE\n";
    cout << "---Linked List---\n";
    cout << "list1 ^ list2: \t";
    PrintDataToScreen(result1);
    cout << "list1 - list2: \t";
    PrintDataToScreen(result3);
    return 0;
}