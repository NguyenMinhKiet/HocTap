#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cstring>
using namespace std;
//khai báo
typedef struct tagNode
{
    char Data;
    struct tagNode *Next;
} * Node;

typedef struct taglist
{
    Node Head; // phần tử đầu
    Node Tail; // phần tử cuối
} LinkedList;
typedef LinkedList Stack;
//Kiểm tra DSLK rỗng?
int isEmpty(Stack st)
{
    if (st.Head == NULL)
        return 0;
    return 1;
}

//Khởi tạo DSLK rỗng
void initLinkedList(Stack &k)
{
    k.Head = k.Tail = NULL;
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
int push(Stack &st, char *x)
{
    Node p = new tagNode;
    if (p == NULL)
        return 0;
    p->Data = x[1];
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
    char x = p->Data;
    delete p;
    return x;
}
// thêm vào sau list
void insertNodeAtTail(Stack &k,Node p, char x)
{
    // if (p == NULL)
    //     return 0;
    p->Data = x;
    p->Next = NULL;
    if (isEmpty(k) == 0)
    {
        k.Head = k.Tail = p;
    }
    else
    {
        k.Tail->Next = p;
        k.Tail = p;
    }
}
//lấy giá trị ở đầu stack
int top(Stack st)
{
    return st.Head->Data;
}

int checkChar(char number)
{
    //isNumber
    if (isdigit(number))
    {
        int num = number - 48;
        return 1;
    }
    // isParentheses
    if (number == '(')
        return 2;
    if (number == ')')
        return 3;
    else
        return 4;
}
int priority(char number, char number1)
{
    if (number == '*' || number == '/')
        number = 1;
    else
        number == 0;
    if (number1 == '*' || number1 == '/')
        number1 = 1;
    else
        number1 == 0;
    if (number == number1)
        return 0;
    if (number < number1)
        return 0;
    else
        return 1;
}
// void BaLanNguoc(Stack &list, char *expression, char *expression1)
// {
//     int i = 0;
//     Node p = new tagNode;
//     p = list.Head;
//     while (i < strlen(expression))
//     {
//         if (checkChar(expression[i]) == 1){
//             expression1[i] = expression[i];
//             i++;
//         }
//         cout<<1;
//         if (checkChar(expression[i]) == 2)
//         {
//             insertNodeAtTail(list,p, expression[i]);
//             i++;
//         }
//         cout<<2;
//         if (checkChar(expression[i]) == 3)
//         {
//             while (checkChar(expression[i]) != 2)
//             {
//                 expression1[i] == p->Data;
//                 p = p->Next;
//                 i++;
//             }
//         }
//         cout<<3;
//         if (checkChar(expression[i] == 4))
//         {
//             if (isEmpty(list) == 0)
//             {
//                 insertNodeAtTail(list,p, expression[i]);
//                 cout<<p->Data;
//                 i++;
//             }
//             else
//             {        
//                 if (priority(expression[i], p->Data))
//                 {
//                     insertNodeAtTail(list,p, expression[i]);
//                     p = p->Next;
//                     i++;
//                 }
//                 else
//                 {
//                     expression1[i] == p->Data;
//                     p = p->Next;
//                     i++;
//                 }
//             }
//         }
//         cout<<4;
//     }
// }
int main()
{
    char *expression;
    char *expression1;
    expression = new char[255];
    expression1 = new char[255];
    Stack(list);
    initLinkedList(list);
    cout << "Nhap bieu thuc: ";
    cin >> expression;
    
    return 0;
}
/* luu tru 3 so : 789 -> 999 -> 9 : 9999789
"-" : so sanh tu cuoi len dau tim ra so lon hon de - (DSLK đôi)

bai 5:  tim hội giao của tập hợp l1 l2:
nối l1 vào l2 -> radix sort -> nếu 2 pt lien tiep = nhau -> luu vào l3: giao else luu vào l4: hội 
bài 7:  matran thưa:

*/