#include <iostream>
using namespace std;
//khai báo
typedef struct tagNode
{
    int Data;
    struct tagNode *Next;
} * Node;
typedef struct tagNodef
{
    double Data;
    struct tagNodef *Next;
} * Nodef;

typedef struct taglist
{
    Node Head; // phần tử đầu
    Node Tail; // phần tử cuối
} LinkedList;

typedef struct taglistf
{
    Nodef Head; // phần tử đầu
    Nodef Tail; // phần tử cuối
} LinkedListf;

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
int getMaxDigit(LinkedList &k)
{
    int max = findMax(k);
    return countDigit(max);
}
// int getNearAverage(LinkedList &k){
//     Node p = k.Head;
//     Node q = k.Head;
//     int sum = 0;
//     int count = 0;
//     while (p){
//         sum+=p->Data;
//         p = p->Next;
//         count++;
//     }
//     float average = sum*1.0/count;
//     float nearest = k.Head->Data,tmp;
//     while (q){
//         tmp = q->Data - average;
//         if (tmp < nearest) nearest = tmp;
//         q = q->Next;
//     }
//     return nearest;
// }
//Câu 1: Tìm phần tử gần giá trị TB nhất
int getNearestAverage(LinkedList &k)
{
    if (k.Head == NULL)
        return 0;
    if (k.Head == k.Tail)
        return k.Head->Data;
    Node p = k.Head;
    int size = 0;
    int number = 0;
    //calculate average number
    while (p)
    {
        number += p->Data;
        size++;
        p = p->Next;
    }
    double average = double(number) / size;
    int val = abs(k.Head->Data - average);
    p = k.Head->Next;
    while (p)
    {
        if (abs(p->Data - average) < val)
            val = abs(p->Data - average);
        p = p->Next;
    }
}
//Câu 2
// int MaxNegativePositive(LinkedList k){
//     Node p = k.Head;
//     Node q = k.Head;
//     int NegativeSum = 0;
//     int PositiveSum = 0;
//     while (p){
//         if(p->Data % 2 == 0){
//             PositiveSum+=p->Data;
//             p = p->Next;
//         }

//     }
// }
//Ex 2 Tính giá trị trung bình âm và giá trị trung bình dương của DSLK đơn, cho biết phần tử âm, dương lớn nhất
void getAverageAndMaxPositiveNegative(LinkedList &k)
{
    Node p = k.Head;
    Node q = k.Head;
    int countPositive = 0;
    int countNegative = 0;
    int sumPositive = 0;
    int sumNegative = 0;
    int maxPositive = k.Head->Data;
    int maxNegative = k.Head->Data;
    //Tính giá trị dương
    while (p)
    {
        if (p->Data > 0)
        {
            if (p->Data > maxPositive)
            {
                maxPositive = p->Data;
            }
            sumPositive += p->Data;
            countPositive++;
        }
        p = p->Next;
    }
    double AveragePositive = (double)sumPositive / countPositive;
    //Tính giá trị âm
    while (q)
    {
        if (q->Data < 0)
        {
            if (q->Data > maxNegative)
            {
                maxNegative = q->Data;
            }
            sumNegative += q->Data;
            countNegative++;
        }
        q = q->Next;
    }
    double AverageNegative = (double)sumNegative / countNegative;
    cout << "Average in Positive = " << AveragePositive << endl;
    cout << "Average in Negative = " << AverageNegative << endl;
    cout << "Max of Positive = " << maxPositive << endl;
    cout << "Max of Negative = " << maxNegative << endl;
}

//Ex3: Tìm 2 phần tử của DSLK đơn = tổng N;
void get2NumberSumN(LinkedList &k, int n)
{
    Node a = NULL;
    Node b = NULL;
    Node i = k.Head, j;
    while (i->Next != NULL)
    {
        Node j = i->Next;
        while (j)
        {
            if (i->Data + j->Data == n)
            {
                a = i;
                b = j;
                return;
            }
            j = j->Next;
        }
        i = i->Next;
    }
}
